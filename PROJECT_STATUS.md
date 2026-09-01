# Project Status

## Current milestone

### M0.1 — One Playable Pad

Status: **IN PROGRESS**

Active work: **Issue #1 — protected single-piezo input**.

### Required outcome

One physical pad must:

- detect soft, medium, and hard hits;
- produce one event per intended strike;
- produce a useful 1–127 velocity range;
- reject normal idle vibration;
- survive hard strikes without exposing the ESP32 ADC to unsafe voltage;
- support short rolls without obvious missed hits.

## Issue #1 state

Completed in repository:

- GPIO0 confirmed as ESP32-C3 ADC1_CH0;
- exact protected-input schematic documented;
- diode orientation documented;
- pre-power continuity procedure documented;
- first-power test procedure documented;
- firmware configured for GPIO0 with 12-bit / 11 dB ADC operation.

Physical evidence still required:

- fit 1 MΩ shunt;
- fit 47 kΩ series resistor;
- fit both Schottky clamps;
- perform continuity/diode-mode checks;
- confirm normal ESP32 boot with the protected input attached.

## Next action

Build `hardware/PROTECTED_INPUT.md` exactly on breadboard/perfboard while unpowered, then record the continuity results in Issue #1 before applying USB power.

## Not yet in scope

- finished enclosure;
- complete drum rack;
- BLE MIDI;
- DIN MIDI;
- 8-channel ADC expansion;
- hi-hat pedal position;
- dual-zone pads;
- cymbal choke;
- production PCB.
