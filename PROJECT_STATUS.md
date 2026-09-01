# Project Status

## Current milestone

### M0.1 — One Playable Pad

Status: **READY TO BUILD**

### Required outcome

One physical pad must:

- detect soft, medium, and hard hits;
- produce one event per intended strike;
- produce a useful 1–127 velocity range;
- reject normal idle vibration;
- survive hard strikes without exposing the ESP32 ADC to unsafe voltage;
- support short rolls without obvious missed hits.

## Next action

Build the protected single-piezo input from `docs/HARDWARE.md`, connect it to one ESP32-C3 ADC-capable pin, flash the serial hit-detector firmware, and collect a 100-hit test set.

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
