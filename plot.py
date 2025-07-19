import serial
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
plt.ion()
fig, ax = plt.subplots()
line, = ax.plot(np.zeros(128))
ax.set_title("Live FFT Spectrum")
ax.set_xlabel("Frequency Bin")
ax.set_ylabel("Magnitude")

while True:
    values = []
    while len(values) < 128:
        try:
            line_raw = ser.readline().decode().strip()
            if line_raw.startswith("Signal Detected") or line_raw.startswith("No signal"):
                continue
            val = float(line_raw)
            values.append(val)
        except:
            continue

    if len(values) == 128:
        line.set_ydata(values)
        ax.relim()
        ax.autoscale_view()
        plt.pause(0.05)
