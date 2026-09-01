# GitHub Issue Backlog

Create these as repository issues in this order.

## #1 — M0.1 Build protected single-piezo input

**Outcome:** one piezo can be struck hard without exposing the ESP32 ADC directly to uncontrolled bipolar spikes.

- [ ] 1 MΩ shunt fitted
- [ ] 47 kΩ series resistor fitted
- [ ] external clamp network fitted
- [ ] ADC-capable GPIO confirmed for exact board
- [ ] continuity / wiring checked

## #2 — M0.1 Build crude 8-inch prototype pad

- [ ] rigid plate
- [ ] rubber/foam playing surface
- [ ] piezo mechanically coupled beneath plate
- [ ] isolation layer/feet
- [ ] no direct stick contact with piezo

## #3 — M0.1 Capture raw piezo peaks

- [ ] firmware builds
- [ ] serial raw peak output works
- [ ] idle baseline recorded
- [ ] soft/medium/hard peaks recorded

## #4 — M0.2 Implement hit window and retrigger control

- [ ] threshold crossing
- [ ] peak capture window
- [ ] retrigger lockout
- [ ] parameters configurable

## #5 — M0.2 Run 100-hit acceptance test

- [ ] >=98/100 intentional hits detected
- [ ] <=2 obvious double triggers
- [ ] 60 s idle without false trigger
- [ ] short roll tested

## #6 — M0.2 Tune velocity curve

- [ ] soft/medium/hard sets captured
- [ ] useful 1–127 span
- [ ] hard hits not all clipped to 127
- [ ] curve parameters documented

## #7 — M0.3 Add MIDI event abstraction

Separate trigger result from transport. A hit should become `{note, velocity, timestamp}` before BLE/DIN code sees it.

## #8 — M0.3 Add BLE MIDI transport

- [ ] channel 10 default
- [ ] configurable note
- [ ] velocity forwarded unchanged
- [ ] reconnect behaviour tested

## #9 — M0.4 Build four-pad prototype

Snare, kick, tom, hi-hat strike.

## #10 — M0.5 Characterise and reduce crosstalk

- [ ] record neighbour responses
- [ ] improve mechanical isolation
- [ ] add bounded software suppression only where required

## #11 — M0.6 Add MCP3008 eight-input front end

- [ ] SPI transport
- [ ] eight channels scanned predictably
- [ ] per-channel calibration
- [ ] no regression in hit latency

## #12 — M0.7 Add hi-hat pedal position sensor

Use Hall sensor + magnet or potentiometer; piezo remains the strike sensor.

## #13 — M0.8 Dual-zone snare experiment

Compare head/rim sensor energy and define a rejection rule for ambiguous hits.

## #14 — M0.9 Cymbal choke experiment

Add edge/choke switch without destabilising piezo strike detection.

## #15 — M1.0 Assemble playable full prototype

Only after all prior gates pass.
