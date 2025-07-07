# Humanscatter

**Humanscatter** is a battery-free communication demonstrator that explores human-powered and ultra-low-power backscatter radio technologies.
## Project Overview

Humanscatter investigates how we can enable rich interactions between humans and computing systems **without batteries**, using only backscatter communication and minimal harvested energy (solar or human power). The project delivers:

- A **carrier-receiver** unit powered by a hand crank
- A backscatter tag
- Real-time wireless communication between the two using **backscatter techniques**
- A MicroPython interface for demonstrability and accessibility

## System Architecture

### 1. **Carrier-Receiver Unit**
- Powered by hand crank (human energy)
- Hosts:
  - Two **CC2500 radios** (one emits carrier, one receives backscatter)
  - A small display for feedback
  - A **Raspberry Pi Pico** as the main controller
- Fully written in **MicroPython**, except low-level SPI functions ported from C

### 2. **Backscatter Tag**
- Solar-powered
- Controls two RF switches to encode data on the reflected signal
- Controlled by a **Raspberry Pi Pico**

---

## ⚙️ Technologies Used

- 🖥️ MicroPython (for code simplicity and accessibility)
- 📻 CC2500 radios for 2.4 GHz communication
- 🧠 Raspberry Pi Pico (RP2040)
- 🔧 Altium Designer for PCB layout
- 📡 SPI protocol for radio communication
- ⚙️ C extensions for critical timing (PIO emulation)

---

## 🚀 Setup & Run

1. **Clone the repository:**

```bash
git clone https://github.com/amau75/Humanscatter.git
cd Humanscatter
