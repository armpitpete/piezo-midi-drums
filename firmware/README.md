# Firmware

The current firmware is intentionally **serial-only**. It proves hit detection before MIDI transport is added.

## Build

From this directory with PlatformIO installed:

```bash
pio run
```

## Flash

```bash
pio run -t upload
pio device monitor
```

## Before flashing

1. Confirm the exact ESP32-C3 SuperMini ADC-capable pin you will use.
2. Update `include/config.h` if necessary.
3. Build the protected piezo input.
4. Do not connect a raw piezo directly to the ADC pin.

## Expected output

```text
HIT raw=742 velocity=25
HIT raw=1610 velocity=64
HIT raw=2840 velocity=120
```

Tune threshold, peak window, velocity ceiling and retrigger lockout from real pad data.
