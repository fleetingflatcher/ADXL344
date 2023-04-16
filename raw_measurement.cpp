//
// Created by corwin on 4/5/2023.
//
#include "raw_measurement.h"
#include <cmath>

raw_measurement::raw_measurement(int16 X, int16 Y, int16 Z) {
    X_value = X;
    Y_value = Y;
    Z_value = Z;
}

// TODO: Short version: For all the following functions, _read needs to be checked.
// Summary: check _read for each function.
// If it has been read already throw an out-of-date flag somewhere
// Still return the old value though.

int16 raw_measurement::X()
{
    return X_value;
}
int16 raw_measurement::Y()
{
    return Y_value;
}
int16 raw_measurement::Z()
{
    return Z_value;
}
// TODO: Check these calculations & rename variables; complete the other TODO expanding the constructor to include previous orientation values
/*
float raw_measurement::calculateRoll() {
    return atan(Y_out / sqrt(pow(X_out, 2) + pow(Z_out, 2))) * 180 / M_PI;
    rollF = 0.94 * rollF + 0.06 * roll;
}
float raw_measurement::calculatePitch() {
    return atan(-1 * X_out / sqrt(pow(Y_out, 2) + pow(Z_out, 2))) * 180 / M_PI;
    pitchF = 0.94 * pitchF + 0.06 * pitch;
}
*/