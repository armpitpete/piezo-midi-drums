#include <Arduino.h>
#include "config.h"

namespace {

using namespace drumkit;

uint32_t lastHitUs = 0;

uint8_t peakToVelocity(uint16_t peak) {
  if (peak <= kTriggerThreshold) {
    return 0;
  }

  const uint16_t capped =
      peak < kVelocityCeilingRaw ? peak : kVelocityCeilingRaw;
  const long mapped = map(
      capped,
      kTriggerThreshold,
      kVelocityCeilingRaw,
      1,
      127);

  return static_cast<uint8_t>(constrain(mapped, 1L, 127L));
}

uint16_t capturePeak(uint16_t firstSample) {
  uint16_t peak = firstSample;
  const uint32_t startedUs = micros();

  while (static_cast<uint32_t>(micros() - startedUs) < kPeakWindowUs) {
    const uint16_t sample = analogRead(kPiezoAdcPin);
    if (sample > peak) {
      peak = sample;
    }
  }

  return peak;
}

}  // namespace

void setup() {
  Serial.begin(115200);
  delay(250);

  analogReadResolution(12);
  pinMode(kPiezoAdcPin, INPUT);

  Serial.println("piezo-midi-drums M0.1 serial hit detector");
  Serial.println("Verify protected input circuit before hard strikes.");
}

void loop() {
  const uint32_t nowUs = micros();
  if (static_cast<uint32_t>(nowUs - lastHitUs) < kRetriggerLockoutUs) {
    return;
  }

  const uint16_t sample = analogRead(kPiezoAdcPin);
  if (sample < kTriggerThreshold) {
    return;
  }

  const uint16_t peak = capturePeak(sample);
  const uint8_t velocity = peakToVelocity(peak);

  if (velocity == 0) {
    return;
  }

  lastHitUs = micros();

  Serial.print("HIT raw=");
  Serial.print(peak);
  Serial.print(" velocity=");
  Serial.println(velocity);
}
