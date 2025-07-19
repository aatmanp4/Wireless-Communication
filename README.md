# Wireless Capacitive Communication

## Aim
To establish a short-range analog communication system between two microcontrollers using capacitive coupling and analyze the received signal for a known frequency (180 kHz) using FFT.

---

## Workflow
1. **Transmitter (TX)** generates a continuous 180 kHz sine wave using an AD9833 waveform generator IC.
2. The signal is transferred through coupling plates that act as a virtual capacitor.
3. **Receiver (RX)** samples the incoming analog signal via ADC.
4. Signal is processed by applying:
   - DC offset removal
   - Fast Fourier Transform (FFT)
   - Peak frequency detection
5. A match near 180 kHz is used to validate signal presence. Detection results are output via:
   - Serial log
   - LED indicator
6. Optional Python script plots the FFT magnitude spectrum live via serial communication.

---

## Explanation
Capacitive coupling allows analog signals to pass through an air gap by forming a high-pass filter between two closely positioned conductive plates. This project exploits that effect by transmitting a clean sine wave at 180 kHz from one microcontroller and receiving it on another, which samples the analog waveform and uses FFT to confirm signal reception.

This approach can be used in high EMI environments, short-range embedded systems, or closed enclosures where RF or wires are impractical.

---

## Technologies Used
- AD9833 Signal Generator (SPI)
- Capacitive coupling using copper plates
- CMSIS DSP Library (for FFT)
- Feather M4 Express or similar MCU with ADC
- Serial communication (USB to host PC)

---

## Tools Used
- **Hardware**: Feather M4 Express, AD9833 breakout, oscilloscope (for verification)
- **Software**: Arduino IDE, Python 3, matplotlib, CMSIS DSP, Adafruit_AD9833 library
- **Visualization**: Python script using `matplotlib` for live FFT spectrum

---

## Methodology
- Generate a clean analog signal at 180 kHz with AD9833
- Set up capacitive plates with minimal gap
- Sample waveform at 1 MSPS using 12-bit ADC
- Remove DC offset from signal
- Apply Real FFT (RFFT) to identify peak frequency
- Compare frequency to expected range (170–190 kHz) and check if magnitude crosses a threshold
- Visualize the FFT results over serial (optional)

---

## Observations
- Signal strength decreases exponentially with distance between plates
- Nearby devices and grounding affect stability and noise floor
- Peak at 180 kHz was reliably detected within ~1 cm gap
- FFT resolution sufficient with 256 points at 1 MHz sampling

---

## Results
- Achieved SNR of approximately 18.7 dB at a noise injection of -12 dB
- Consistent signal detection and peak tracking within ±5 kHz of expected frequency
- LED indicator and serial logs provided clear confirmation of reception

---


