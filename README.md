# Piezo MIDI Drums

A velocity-sensitive electronic drum kit built from piezo sensors and an ESP32-C3, starting with one reliable pad and expanding to an 8-input MIDI drum brain.

## Project goal

Build a playable electronic drum kit where physical strikes are converted into stable MIDI note events with useful velocity, low latency, low false-trigger rate, and controlled crosstalk.

## First milestone — M0.1: One Playable Pad

**ESP32-C3 + protected piezo input + one 8-inch pad → reliable velocity values from 1–127.**

M0.1 deliberately excludes BLE MIDI, multi-pad scanning, enclosures, dual-zone sensing, and cosmetic fabrication. The first job is to prove that one pad feels playable.

## System direction

```text
Drum pad
  ↓
Piezo sensor
  ↓
Protected analog input
  ↓
ESP32-C3 hit detector
  ↓
Peak capture + velocity curve
  ↓
MIDI drum event
  ↓
Computer / synth / drum sampler
```

Later expansion:

```text
8 piezo inputs → MCP3008 → SPI → ESP32-C3 → MIDI
```

## Repository map

- `firmware/` — PlatformIO firmware for the ESP32-C3
- `hardware/` — bill of materials and physical/electrical build notes
- `docs/BUILD_PLAN.md` — staged implementation plan
- `docs/HARDWARE.md` — protected piezo input and expansion architecture
- `docs/ARCHITECTURE.md` — system boundaries and trigger pipeline
- `docs/ACCEPTANCE.md` — measurable acceptance gates
- `docs/MIDI_MAP.md` — default General MIDI drum mapping
- `docs/GITHUB_ISSUES.md` — issue backlog ready to create on GitHub
- `PROJECT_STATUS.md` — current state and next action

## Safety / electrical boundary

A piezo disc can generate voltage spikes well above the ESP32's 3.3 V input range. **Do not connect a piezo directly to an ESP32 GPIO/ADC pin.** Use the protected input described in `docs/HARDWARE.md`.

## Current status

**M0.1 — planned / scaffolded.**

Next action: build and test one protected piezo input and one crude pad before expanding the system.
