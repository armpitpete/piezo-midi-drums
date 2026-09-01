# Acceptance Gates

## M0.1 — one playable pad

A candidate passes when all of the following are demonstrated on the physical prototype.

### Trigger reliability

- 100 deliberate single strikes tested;
- at least 98 are detected;
- no more than 2 obvious double-triggers;
- no false trigger during a 60-second hands-off idle test.

### Dynamic response

Soft, medium, and hard playing must produce visibly distinct velocity populations. Exact numbers are not fixed, but a healthy result should span much of 1–127 rather than clustering around one value.

Suggested target regions:

- soft: roughly 20–50;
- medium: roughly 50–95;
- hard: roughly 95–127.

These are tuning targets, not strict bins.

### Retrigger behaviour

- normal single hits produce one event;
- short rolls remain playable;
- lockout must not mask obviously intentional consecutive hits.

### Electrical boundary

The ESP32 ADC must only receive the protected/clamped signal. Do not intentionally stress-test an unclamped GPIO with hard piezo strikes.

## M0.4 — four-pad prototype

- each pad passes its own M0.1-style reliability check;
- striking one pad does not routinely trigger another;
- simultaneous playing does not collapse scan performance;
- per-pad threshold and velocity calibration are possible.

## M1.0 — full prototype

- kick, snare, toms, hi-hat and cymbal roles are playable;
- MIDI mapping is configurable;
- crosstalk is controlled in the assembled frame;
- velocity remains expressive across the kit;
- power cycling restores a known configuration;
- no individual piezo is connected directly to an MCU ADC without protection.
