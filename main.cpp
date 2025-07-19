#include <Arduino.h>
#include <arm_math.h>
#include <arm_const_structs.h>

#define ADC_PIN A1
#define LED_PIN 13
#define FFT_SIZE 256
#define SAMPLE_RATE 1000000  // 1 MSPS
#define TRIGGER_THRESHOLD 2000

float adc_buffer[FFT_SIZE];
float fft_input[FFT_SIZE];
float fft_output[FFT_SIZE];
float fft_magnitude[FFT_SIZE / 2];

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  analogReadResolution(12);  // 12-bit ADC
  analogReference(AR_DEFAULT);

  for (int i = 0; i < 10; i++) analogRead(ADC_PIN);

  Serial.println("Receiver initialized. Awaiting signal...");
}

void loop() {
  for (int i = 0; i < FFT_SIZE; i++) {
    adc_buffer[i] = analogRead(ADC_PIN);
    delayMicroseconds(1000000 / SAMPLE_RATE);
  }

  float avg = 0;
  for (int i = 0; i < FFT_SIZE; i++) avg += adc_buffer[i];
  avg /= FFT_SIZE;
  for (int i = 0; i < FFT_SIZE; i++) fft_input[i] = adc_buffer[i] - avg;

  arm_rfft_fast_instance_f32 fft_instance;
  arm_rfft_fast_init_f32(&fft_instance, FFT_SIZE);
  arm_rfft_fast_f32(&fft_instance, fft_input, fft_output, 0);
  arm_cmplx_mag_f32(fft_output, fft_magnitude, FFT_SIZE / 2);

  int peak_index = 0;
  float peak_value = 0;
  for (int i = 1; i < FFT_SIZE / 2; i++) {
    if (fft_magnitude[i] > peak_value) {
      peak_value = fft_magnitude[i];
      peak_index = i;
    }
  }

  float frequency_bin = (float)SAMPLE_RATE / FFT_SIZE;
  float detected_freq = peak_index * frequency_bin;

  if (detected_freq > 170000 && detected_freq < 190000 && peak_value > TRIGGER_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH);
    Serial.print("Signal Detected: ");
    Serial.print(detected_freq);
    Serial.print(" Hz, Peak: ");
    Serial.println(peak_value);
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("No valid signal detected.");
  }

  delay(500);
}
