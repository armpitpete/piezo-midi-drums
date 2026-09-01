#pragma once

#include <Arduino.h>

namespace drumkit {

// IMPORTANT: verify this is an ADC-capable pin on the exact ESP32-C3 SuperMini
// revision before wiring hardware. GPIO0 is only a prototype default.
constexpr uint8_t kPiezoAdcPin = 0;

constexpr uint16_t kAdcMax = 4095;
constexpr uint16_t kTriggerThreshold = 180;
constexpr uint16_t kVelocityCeilingRaw = 3000;

constexpr uint32_t kPeakWindowUs = 8000;
constexpr uint32_t kRetriggerLockoutUs = 25000;

}  // namespace drumkit
