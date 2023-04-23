//
// Created by corwin on 4/5/2023.
//
#include "raw_measurement.h"
#include <cmath>

RawMeasurement::RawMeasurement(int16_t X, int16_t Y, int16_t Z) {
    X_value = X;
    Y_value = Y;
    Z_value = Z;
    pitch_value = calculatePitch();
    roll_value = calculateRoll();
}

float RawMeasurement::calculatePitch() {
  return -atan2(-X_value, Z_value) * 180 / M_PI;
}
float RawMeasurement::calculateRoll() {
  return atan2(Y_value, Z_value) * 180 / M_PI;
}