# Issue #1 — Protected Single-Piezo Input

This is the exact M0.1 breadboard circuit for the first pad.

## Confirmed ADC pin

Use **GPIO0 / ADC1_CH0** on the ESP32-C3 SuperMini. On common boards the header is marked `0`, `IO0`, or `A0`.

Do not choose the pin by counting header positions: SuperMini clones vary. Identify the GPIO by its silkscreen/board documentation.

ESP32-C3 ADC1 channels are GPIO0–GPIO4. GPIO0 is selected because it is an ADC1 channel and is not one of the ESP32-C3 boot-strapping GPIOs.

## Parts

| Ref | Part | Value / type | Purpose |
|---|---|---|---|
| PZ1 | Piezo disc | 27–35 mm | Impact transducer |
| R1 | Resistor | 1 MΩ | Piezo discharge / baseline |
| R2 | Resistor | 47 kΩ | Limits transient/clamp current |
| D1 | Schottky diode | BAT54, BAT85, or equivalent | Upper clamp |
| D2 | Schottky diode | BAT54, BAT85, or equivalent | Lower clamp |
| C1 | Ceramic capacitor | 100 nF | Local 3.3 V decoupling near clamps |

If using a dual diode such as BAT54S, verify the package pinout from that exact part's datasheet rather than assuming pin order.

## Exact schematic

```text
                       R2 47 kΩ
 PZ1 + o───────┬──────/\/\/\/──────●──────── GPIO0 / ADC1_CH0
               │                    │
               │                    ├────|<|──── 3V3
               │                    │     D1
              R1                    │
             1 MΩ                   └────|>|──── GND
               │                          D2
 PZ1 - o───────┴────────────────────────── GND

 3V3 o──────────────||────────────── GND
                    C1 100 nF
```

### Diode orientation

For the **upper clamp D1**:

- **anode → ADC node**
- **cathode / stripe → 3.3 V**

For the **lower clamp D2**:

- **anode → GND**
- **cathode / stripe → ADC node**

The two diodes therefore conduct only when the ADC node tries to leave the supply rails by roughly one Schottky forward drop.

## Wiring order

1. Leave the ESP32 **unpowered**.
2. Join PZ1 negative to GND.
3. Fit R1 (1 MΩ) between PZ1 positive and GND.
4. Fit R2 (47 kΩ) from PZ1 positive to a new node named `ADC_IN`.
5. Connect `ADC_IN` to GPIO0.
6. Fit D1 from `ADC_IN` to 3V3: anode at `ADC_IN`, cathode/stripe at 3V3.
7. Fit D2 from GND to `ADC_IN`: anode at GND, cathode/stripe at `ADC_IN`.
8. Fit C1 (100 nF) between 3V3 and GND close to the clamp diodes/ESP32 header.

## Pre-power continuity checks

With USB/power disconnected and the piezo not being struck:

| Test | Expected |
|---|---|
| 3V3 → GND resistance | not a short |
| GPIO0/ADC_IN → GND | not a direct short |
| PZ1+ → GND | approximately 1 MΩ (meter may be influenced by diode paths depending on polarity) |
| R2 end-to-end | approximately 47 kΩ |
| D1 diode mode, ADC_IN → 3V3 | Schottky forward drop in the forward direction; open/reverse in the other direction |
| D2 diode mode, GND → ADC_IN | Schottky forward drop in the forward direction; open/reverse in the other direction |

If diode-mode readings are confusing because the circuit is assembled, lift one diode leg and test the diode separately. Do not power the board until diode orientation is known.

## First power-up

1. Power the ESP32 with the piezo connected but **do not strike it yet**.
2. Confirm the board boots and USB serial remains available.
3. Run the M0.1 firmware and confirm the idle ADC remains below the trigger threshold most of the time.
4. Tap the pad/piezo lightly and confirm a hit is reported.
5. Increase strike force gradually; do not start with maximum-force hits.

The firmware uses 11 dB ADC attenuation so the ESP32-C3 can measure approximately 0–2.5 V before ADC saturation. Saturation above that is acceptable for protection testing but repeated saturation means the later velocity front end/curve needs tuning.

## Protection rationale

Espressif specifies GPIO input levels down to about -0.3 V and up to VDD + 0.3 V. External Schottky clamps are intended to prevent a piezo's bipolar transient from reaching the GPIO uncontrolled.

R2 limits the current when the clamp conducts. As an illustrative upper-bound calculation, a hypothetical +100 V piezo transient with a ~3.6 V clamp produces approximately:

```text
(100 V - 3.6 V) / 47,000 Ω ≈ 2.05 mA
```

A real piezo pulse is brief and source-limited; this calculation explains why a relatively large series resistor is used. It is not a substitute for measuring the physical prototype.

## Preferred validation

If an oscilloscope is available, observe `ADC_IN` while progressing from light to hard strikes. The desired evidence is that the node stays close to the 0–3.6 V GPIO range while the raw piezo side is allowed to swing much further.

Without a scope, Issue #1 can still pass the construction/continuity gate, but the stronger transient evidence should be captured later if test equipment becomes available.

## Issue #1 completion evidence

Issue #1 is complete only when the physical build confirms:

- R1 = 1 MΩ fitted;
- R2 = 47 kΩ fitted;
- D1/D2 fitted with verified orientation;
- GPIO0 / ADC1_CH0 used;
- no 3V3-to-GND short;
- continuity/diode-mode checks pass;
- ESP32 boots normally with the protected input attached.

## References

- Espressif ESP32-C3 Series Datasheet — GPIO0 is ADC1_CH0; GPIO input high level is specified up to VDD + 0.3 V and low level down to -0.3 V.
- Espressif Arduino-ESP32 ADC documentation — ESP32-C3 `ADC_11db` measurable range is approximately 0–2.5 V.
