//
// Created by corwin on 4/5/2023.
//
#include "measurement.h"
#include <cmath>

Measurement::Measurement(int16 X, int16 Y, int16 Z) {
    X = X_value;
    Y = Y_value;
    Z = Z_value;
}

// TODO: Short version: For all the following functions, _read needs to be checked.
// Summary: check _read for each function.
// If it has been read already throw an out-of-date flag somewhere
// Still return the old value though.

// COMMENT: This means
int16 Measurement::X()
{
    X_read = true;
    return X_value;
}
int16 Measurement::Y()
{
    Y_read = true;
    return Y_value;
}
int16 Measurement::Z()
{
    Z_read = true;
    return Z_value;
}
// TODO: Check these calculations & rename variables; complete the other TODO expanding the constructor to include previous orientation values
/*
float Measurement::calculateRoll() {
    return atan(Y_out / sqrt(pow(X_out, 2) + pow(Z_out, 2))) * 180 / M_PI;
    rollF = 0.94 * rollF + 0.06 * roll;
}
float Measurement::calculatePitch() {
    return atan(-1 * X_out / sqrt(pow(Y_out, 2) + pow(Z_out, 2))) * 180 / M_PI;
    pitchF = 0.94 * pitchF + 0.06 * pitch;
}
*/