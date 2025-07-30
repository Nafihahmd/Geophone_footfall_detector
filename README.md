**Geophone Footfall Detector**

A complete open‑source solution for building and deploying geophone‑based footfall detectors. Each detector node uses an ESP32‑C6 microcontroller, an ADS1115 16‑bit analog‑to‑digital converter (ADC), and a TLC272 low‑noise amplifier to sense ground vibrations. Detector nodes communicate wirelessly via ESP‑NOW to a Raspberry Pi control center that collects, timestamps, and visualizes footfall events in real time.

---

## 📝 Table of Contents

1. [Project Overview](#project-overview)
2. [Features](#features)
3. [Hardware](#hardware)

   * [Bill of Materials](#bill-of-materials)
   * [Schematics & PCB](#schematics--pcb)
   * [3D Printable Enclosure](#3d-printable-enclosure)
4. [Software](#software)

   * [Arduino Sketches](#arduino-sketches)
   * [Raspberry Pi Control Center](#raspberry-pi-control-center)
5. [Directory Structure](#directory-structure)
6. [Getting Started](#getting-started)
7. [Usage](#usage)
8. [Contributing](#contributing)
9. [License](#license)

---

## Project Overview

This repository hosts all the files and documentation needed to build and operate a distributed network of geophone footfall detectors. Each node:

* **Senses** ground vibrations using a geophone sensor, amplified by a TLC272 op‑amp.
* **Converts** the analog signal via an ADS1115 external ADC for high‑resolution sampling.
* **Processes** and filters vibration data on an ESP32‑C6.
* **Communicates** detected events to a central Raspberry Pi over ESP‑NOW (low‑latency, peer‑to‑peer Wi‑Fi).

Collected data on the Pi can be logged, plotted, or fed into an alerting/analytics pipeline.

---

## Features

* High‑sensitivity footfall detection using a geophone + TLC272 amplifier.
* 16‑bit sampling with ADS1115 for low‑noise, accurate waveform capture.
* Low‑power, mesh‑capable ESP‑NOW networking for robust multi‑node deployment.
* Modular hardware design: PCB files and 3D‑printable enclosure.
* Arduino IDE–based firmware with example sketches and configuration.
* Python scripts on Raspberry Pi for data aggregation and visualization.

---

## Hardware

### Bill of Materials

| Component             | Part Number     | Quantity  | Notes                                   |
| --------------------- | --------------- | --------- | --------------------------------------- |
| ESP32‑C6 module       | ESP32‑C6‑DevKit | 1         | Development board with on‑board antenna |
| ADS1115 ADC           | ADS1115         | 1         | I²C, 16‑bit                             |
| Operational Amp       | TLC272          | 1         | Low‑noise, dual channel                 |
| Geophone Sensor       | SM‑24           | 1         | 4.5 Hz resonant frequency               |
| PCB                   | —               | 1         | Custom designed (see schematics)        |
| Fasteners & Standoffs | —               | As needed | For mounting PCB in enclosure           |

### Schematics & PCB

* **Location**: `hardware/PCB/`
* KiCad schematic and PCB layout files.
* Gerber exports for fabrication.

### 3D Printable Enclosure

* **Location**: `hardware/enclosure/`
* STL and STEP files for the detector housing.
* Snap‑fit design to secure the PCB and weather‑proof the sensor port.

---

## Software

### Arduino Sketches

* **Location**: `src/`
* **Main Sketch**: `footfall_detector.ino`
* **Modules**:

  * `SensorReader.cpp/.h`: configures ADS1115 and reads geophone data.
  * `AmplifierControl.cpp/.h`: sets up TLC272 gain stages (if programmable).
  * `NetworkManager.cpp/.h`: initializes ESP‑NOW, peers, and message handling.

### Raspberry Pi Control Center

* **Location**: `pi/`
* **Components**:

  * `receiver.py`: listens for ESP‑NOW packets via a Wi‑Fi dongle on the Pi.
  * `visualizer.py`: plots time‑series data of events (matplotlib).
  * `logger.py`: logs events to CSV or a database.

---

## Getting Started

1. **Clone repository**

   ```bash
   git clone https://github.com/Nafihahmd/Geophone_footfall_detector.git
   cd Geophone_footfall_detector
   ```

2. **Install dependencies**


3. **Build & upload firmware**


4. **Assemble hardware**

   * Order PCB using `hardware/PCB/gerbers/`.
   * 3D print enclosure from `hardware/enclosure/`.
   * Solder components and mount in enclosure.

5. **Run control center**

   ```bash
   cd pi
   python3 receiver.py
   python3 logger.py
   python3 visualizer.py
   ```

---

## Usage

1. Power on each detector; nodes will automatically join ESP‑NOW network.
2. The Raspberry Pi will receive footfall event packets, timestamp them, and log/display in real time.
3. View the live plot at `http://<pi-ip>:5000` (if using a Flask wrapper in `visualizer.py`).

---

## Contributing

Contributions are welcome! Please open issues and PRs, or use the issue templates in `.github/ISSUE_TEMPLATE.md`. See `CONTRIBUTING.md` for coding standards and commit message guidelines.

---

## License

This project is released under the **MIT License**. See `LICENSE` for details.
