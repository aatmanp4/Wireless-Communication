#include <SPI.h>
#include <Adafruit_AD9833.h>

#define FSYNC_PIN 10
Adafruit_AD9833 ad9833 = Adafruit_AD9833(FSYNC_PIN);

void setup() {
  Serial.begin(115200);
  ad9833.begin();
  ad9833.setWaveForm(AD9833_SINE);
  ad9833.setFrequency(AD9833_FREQ0, 180000); // Set to 180 kHz
  ad9833.enableOutput(true);
  Serial.println("Transmitting 180 kHz sine wave...");
}

void loop() {
  // signal output is continuous so leave this blank
}
