# ESP32 WROOM-32 Starter Template

A production-ready starter template for ESP32 WROOM-32 development using VS Code and PlatformIO. Configured with baud optimizations, exception decoding, and strict dependency isolation.

---

## Prerequisites

Before running this project, ensure you have:

1. **VS Code** installed.
2. **PlatformIO IDE Extension** installed in VS Code:
* Open VS Code Extensions (`Ctrl + Shift + X`).
* Search for `PlatformIO IDE` and install it.


3. **USB-to-UART Bridge Driver** for your board:
* **CP2102:** Install the Silicon Labs CP210x VCP driver.
* **CH340:** Install the WCH CH340 driver.
* *Verify:* Plug the board into USB, open **Device Manager**, expand **Ports (COM & LPT)**, and ensure a COM port is assigned without warnings.



---

## Quick Start

### 1. Clone the Repository

```bash
git clone https://github.com/<your-username>/<repo-name>.git
cd <repo-name>

```

### 2. Open in VS Code

Open the project root folder directly in VS Code:

```bash
code .

```

PlatformIO will automatically detect `platformio.ini`, download the required Espressif 32 platform toolchain, and index the project.

### 3. Connect the Hardware

* Plug your ESP32 WROOM-32 board into a USB port using a **data-capable** cable (not a charge-only cable).

### 4. Build, Flash & Monitor

Use the status bar shortcuts at the bottom of VS Code or the PlatformIO CLI:

| Action | VS Code Bottom Bar Icon | CLI Command |
| --- | --- | --- |
| **Compile** | Checkmark (`✓`) | `pio run` |
| **Upload to ESP32** | Right Arrow (`→`) | `pio run --target upload` |
| **Serial Monitor** | Plug Icon (`🔌`) | `pio device monitor` |

> **Upload Tip:** If the terminal stalls at `Connecting........_____.....`, press and hold the physical **BOOT** (or **IO0**) button on the ESP32 board until flashing begins, then release it.

---

## Development Guidelines

### Adding External Libraries

Never manually paste `.zip` files or global Arduino libraries into the repository. Always add them to the `lib_deps` section inside `platformio.ini`:

```ini
lib_deps =
    bblanchon/ArduinoJson @ ^7.0.0
    knolleary/PubSubClient @ ^2.8

```

PlatformIO downloads, locks, and stores these libraries inside `.pio/libdeps/` per project, preventing cross-project conflicts.

### Monitoring & Crash Debugging

* The serial monitor baud rate is set to **`115200`**. Ensure all `Serial.begin(115200);` calls in code match this value.
* The `esp32_exception_decoder` filter is active. If your firmware triggers a panic or core dump, the monitor will automatically translate register memory addresses into human-readable C++ filenames and line numbers.

### Repository Hygiene

The project includes a `.gitignore` tailored for embedded builds. Never remove the `.pio/` entry, as compiled binaries (`*.bin`, `*.elf`) and build caches should not be tracked by Git.