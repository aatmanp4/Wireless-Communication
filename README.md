# Wireless Capacitive Communication

## 🎯 Aim
Enable short-range data transfer using capacitive coupling and embedded signal modulation.

## 🔄 Workflow
- Signal generation using AD9833 (180kHz sine wave)
- Signal transmitted via coupling plates
- ADC on RX MCU captures the waveform
- FIR filtering and FFT used for detection

## 📖 Explanation
This project leverages capacitive coupling between two microcontrollers (MCUs) to establish a wireless analog data channel. A sine wave generated on the transmitter MCU is passed through an air-gap capacitor and received as an attenuated analog signal. The receiver processes this signal using digital filtering and spectrum analysis (FFT) to identify presence and frequency.

## 💻 Technologies Used
- Embedded C (Arduino/Feather M4 Express)
- FFT Libraries (CMSIS-DSP or ArduinoFFT)
- MATLAB (for modeling)
- AD9833 Signal Generator
- Serial Interface to PC

## ⚙️ Tools
- Adafruit Feather M4 Express
- Oscilloscope for debugging
- Python (for logging and visualization)
- FFT + SNR calculation scripts

## 🧠 Methodology
- Generate clean 180 kHz waveform
- Analyze signal loss through capacitance
- Use ADC sampling and FFT to measure peak

## 📈 Observations
- Best coupling with < 1cm air gap
- Noise near 200kHz but distinguishable peak at 180kHz

## ✅ Results
- SNR achieved: ~18.7 dB at -12 dB noise injection
