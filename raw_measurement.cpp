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


float RawMeasurement::calculateRoll() { return 0; }
float RawMeasurement::calculatePitch() {
    return atan((Y_value/Z_value) * (1 / sqrt(pow(Y_value, 2) + pow(Z_value, 2))));
	//return atan(-1 * X_out / sqrt(pow(Y_out, 2) + pow(Z_out, 2))) * 180 / M_PI;
}