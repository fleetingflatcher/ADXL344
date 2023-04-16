//
// Created by corwin on 4/5/2023.
//

#include <stdint.h>

#include <Arduino.h>
#include <Wire.h>

#include "raw_measurement.h"

#ifndef ADXL344_H
#define ADXL344_H

class ADXL344 {
public :
    void setup() ;
    void setRange() ;
    void changeOffset();
    void changeOffsetX();
    void changeOffsetY();
    void changeOffsetZ();
    void takeNewMeasurement();
    void resetMeasurement();

private:
    int rangeDivider = 256;
    const int address = 0x53; // The adxl344 sensor I^2C address
};

#endif //ADXL344_H