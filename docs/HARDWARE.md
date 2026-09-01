# Hardware

## M0.1 protected piezo input

A piezo can generate large bipolar spikes. The ESP32-C3 ADC is a 3.3 V input and must be protected.

### Recommended prototype circuit

```text
                       47 kΩ
Piezo + ────────┬────/\/\/\/─────●──── ESP32 ADC
                │                 │
               1 MΩ          Schottky clamps
                │             to 3.3 V + GND
Piezo - ────────┴─────────────────┴──── GND
```

Use:

- 27–35 mm piezo disc;
- 1 MΩ resistor across the piezo;
- 47 kΩ series resistor to the ADC;
- low-forward-voltage Schottky clamps, e.g. BAT54/BAT54S arrangement;
- common ground between sensor circuit and ESP32;
- an ADC-capable GPIO selected for the exact ESP32-C3 SuperMini board revision.

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

- clamp positive excursions near the 3.3 V rail;
- clamp negative excursions near ground;
- avoid relying only on undocumented/internal protection behaviour.

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
