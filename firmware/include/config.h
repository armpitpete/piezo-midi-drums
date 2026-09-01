#pragma once

#include <Arduino.h>

namespace drumkit {

// ESP32-C3: GPIO0 is ADC1_CH0. On common SuperMini boards use the header
// labelled 0 / IO0 / A0. Do not identify the pin by physical position alone.
constexpr uint8_t kPiezoAdcPin = 0;

constexpr uint16_t kAdcMax = 4095;
constexpr uint16_t kTriggerThreshold = 180;
constexpr uint16_t kVelocityCeilingRaw = 3000;

constexpr uint32_t kPeakWindowUs = 8000;
constexpr uint32_t kRetriggerLockoutUs = 25000;

}  // namespace drumkit
