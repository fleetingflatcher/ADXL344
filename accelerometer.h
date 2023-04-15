//
// Created by corwin on 4/5/2023.
//
#include <Arduino.h>
#include <Wire.h>

#include "measurement.h"

#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

class Accelerometer {
public :
    Measurement measurement;
    void setup() ;
    void setRange() ;
private:
    int rangeDivider = 256;
    const int address = 0x53; // The adxl344 sensor I^2C address
    void takeNewMeasurement();

};

#endif //ACCELEROMETER_H