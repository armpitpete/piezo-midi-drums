# Architecture

## Core pipeline

```text
IMPACT
  ↓
PIEZO TRANSDUCER
  ↓
INPUT PROTECTION
  ↓
ADC SAMPLE
  ↓
THRESHOLD CROSSING
  ↓
PEAK CAPTURE WINDOW
  ↓
VELOCITY CURVE
  ↓
RETRIGGER / CROSSTALK POLICY
  ↓
MIDI EVENT
```

## Responsibilities

### Mechanical layer

- transfer stick/foot impact into the piezo;
- provide useful sensitivity;
- isolate neighbouring pads;
- avoid direct concentrated force on the ceramic disc.

### Electrical layer

- discharge the piezo between hits;
- limit current;
- clamp positive and negative transients;
- present a safe 0–3.3 V signal to the ADC.

### Trigger layer

- detect a candidate hit;
- capture the local peak;
- reject tiny vibration;
- prevent one strike becoming multiple triggers;
- preserve fast intentional rolls.

### Mapping layer

- convert raw peak magnitude to MIDI velocity 1–127;
- support tunable curves rather than one hard-coded response.

### MIDI layer

- use channel 10 by default;
- map each pad to a configurable drum note;
- remain independent of the eventual transport: BLE, DIN, or native USB on a later controller.

## Design rule

The system should keep **hit detection**, **velocity mapping**, and **MIDI transport** separate so each can be tested independently.
