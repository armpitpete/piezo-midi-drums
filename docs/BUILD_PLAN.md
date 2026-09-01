# Build Plan

## Phase 1 — one pad

1. Build one crude 8-inch pad.
2. Mount one 27–35 mm piezo beneath the strike plate.
3. Build the protected analogue input.
4. Select and verify an ADC-capable ESP32-C3 pin.
5. Flash the serial-only hit detector.

### Exit gate

The ESP32 reports a stable raw peak for intentional hits without obvious idle triggering.

## Phase 2 — hit detection

Implement and tune:

- threshold;
- peak-capture window;
- retrigger lockout;
- raw peak logging.

Initial defaults:

- peak window: 8 ms;
- retrigger lockout: 25 ms;
- threshold: board/pad dependent and must be calibrated.

### Exit gate

A single strike normally creates one event; deliberate short rolls remain detectable.

## Phase 3 — velocity

Map the peak to MIDI-style velocity 1–127.

Test at least:

- 30 soft hits;
- 30 medium hits;
- 30 hard hits;
- 10 deliberately awkward/off-centre hits.

### Exit gate

Soft, medium, and hard groups are meaningfully separated and hard hits do not all pin at 127.

## Phase 4 — MIDI output

Add a transport only after hit detection is stable.

Preferred order:

1. serial debug event;
2. BLE MIDI on ESP32-C3;
3. optional 5-pin DIN MIDI;
4. consider ESP32-S3/RP2040/Teensy if native USB MIDI becomes a requirement.

## Phase 5 — four pads

Build:

- snare;
- kick;
- tom;
- hi-hat strike pad.

Test one pad at a time, then simultaneous physical mounting.

## Phase 6 — crosstalk

1. Strike each pad strongly.
2. Record all channels during the same time window.
3. Identify weak neighbouring responses.
4. Improve mechanical isolation first.
5. Add software crosstalk rejection only where necessary.

## Phase 7 — eight channels

Add MCP3008 and move to a predictable multi-input scan loop.

## Phase 8 — hi-hat pedal

Add continuous pedal position using Hall sensor or potentiometer.

Map states such as:

- open;
- half-open;
- closed;
- fast close / chick.

## Phase 9 — advanced zones

- dual-zone snare;
- rim detection;
- cymbal edge/choke;
- ride bow/bell experiments.

## Phase 10 — full prototype

Only now design:

- permanent pad shells;
- wiring harness;
- drum brain enclosure;
- connectors;
- power arrangement;
- production PCB if justified.
