# Hardware

## M0.1 protected piezo input

A piezo can generate large bipolar spikes. The ESP32-C3 ADC is a 3.3 V input and must be protected.

The exact Issue #1 breadboard wiring, diode orientation, continuity tests, and first-power procedure are in [`hardware/PROTECTED_INPUT.md`](../hardware/PROTECTED_INPUT.md).

### Confirmed prototype ADC

Use **GPIO0 / ADC1_CH0**. On common ESP32-C3 SuperMini boards this is exposed on a header labelled `0`, `IO0`, or `A0`. Identify it by label rather than by assuming a physical header position.

Espressif documents ADC1 on GPIO0–GPIO4; GPIO0 maps to ADC1_CH0. GPIO2 is boot-strapping-sensitive, so GPIO0 is the cleaner first-pad choice.

### Prototype circuit

```text
                       47 kΩ
Piezo + ────────┬────/\/\/\/─────●──── GPIO0 / ADC1_CH0
                │                 │
               1 MΩ           upper Schottky → 3V3
                │             lower Schottky ← GND
Piezo - ────────┴─────────────────┴──── GND
```

Use:

- 27–35 mm piezo disc;
- 1 MΩ resistor across the piezo;
- 47 kΩ series resistor to the ADC;
- two low-forward-voltage Schottky clamps, e.g. BAT54/BAT85 or equivalent;
- 100 nF local 3.3 V decoupling capacitor near the clamp/MCU connection;
- common ground between sensor circuit and ESP32;
- GPIO0 / ADC1_CH0 for the first-pad prototype.

The values are a safe prototype starting point, not a final analogue front end.

## Why each part exists

**1 MΩ shunt resistor**

- gives the piezo a discharge path;
- returns the input toward ground after the strike;
- prevents charge lingering indefinitely.

**47 kΩ series resistor**

- limits clamp current from large piezo pulses;
- reduces stress on the ESP32 input and clamp network.

**External Schottky clamps**

- clamp positive excursions toward the 3.3 V rail;
- clamp negative excursions toward ground;
- avoid relying only on internal GPIO protection behaviour.

**100 nF local supply decoupling**

- provides a local reservoir for the small transient current diverted into the 3.3 V rail by the upper clamp;
- complements the board's normal supply decoupling.

## ADC configuration

The M0.1 firmware uses 12-bit reads and 11 dB attenuation. Espressif's Arduino documentation gives an ESP32-C3 measurable range of approximately 0–2.5 V at 11 dB attenuation. The electrical protection remains responsible for preventing the pin itself from leaving the safe GPIO range; ADC attenuation does not provide over-voltage protection.

## Prototype pad stack

```text
Rubber / foam playing surface
─────────────────────────────
Rigid strike plate
─────────────────────────────
Piezo coupled beneath plate
─────────────────────────────
Foam isolation
─────────────────────────────
Base
```

Do not strike the ceramic disc directly.

## M0.1 physical default

- approximately 8-inch playing surface;
- plywood or similar rigid plate;
- 5–10 mm rubber/foam top;
- 27 mm piezo bonded beneath the plate;
- soft isolation feet.

The point is testability, not appearance.

## Eight-channel expansion

After the single-pad and four-pad gates pass:

```text
Piezo 1 ─┐
Piezo 2 ─┤
Piezo 3 ─┤
Piezo 4 ─┤
Piezo 5 ─┤── MCP3008 ── SPI ── ESP32-C3
Piezo 6 ─┤
Piezo 7 ─┤
Piezo 8 ─┘
```

Each piezo still needs its own appropriate protection network before the ADC input.

## Hi-hat exception

A piezo is suitable for the hi-hat **strike**. Continuous pedal position should use a Hall-effect sensor + magnet or potentiometer.
