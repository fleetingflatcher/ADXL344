//
// Created by corwin on 4/5/2023.
//

#include "ADXL344.h"

// TODO: read through this; make sure it makes sense.
// TODO: More than that, make sure there are no config registers we're missing.
void ADXL344::setup (int8_t X_Offset, int8) {
    Wire.begin(); // Initiate the Wire library
    // Set adxl344 in measuring mode
    Wire.beginTransmission(address); // Start communicating with the device
    Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
    // Enable measurement
    Wire.write(8); // Bit D3 High for measuring enable (8dec -> 0000 1000 binary)
    Wire.endTransmission();
    delay(10);

    //Off-set Calibration
    //X-axis
    Wire.beginTransmission(address);
    Wire.write(0x1E);
    Wire.write(1);
    Wire.endTransmission();
    delay(10);
    //Y-axis
    Wire.beginTransmission(address);
    Wire.write(0x1F);
    Wire.write(-2);
    Wire.endTransmission();
    delay(10);

    //Z-axis
    Wire.beginTransmission(address);
    Wire.write(0x20);
    Wire.write(-9);
    Wire.endTransmission();
    delay(10);
}
// TODO: check the logic here
void ADXL344::takeNewMeasurement() {
    Wire.beginTransmission(address);
    Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(address, 6, true);


    int16 X_out = ( Wire.read() | Wire.read() << 8); // X-axis value
    int16 Y_out = ( Wire.read() | Wire.read() << 8); // Y-axis value
    int16 Z_out = ( Wire.read() | Wire.read() << 8); // Z-axis value

    //Measurement nextMeasurement(X_out, Y_out, Z_out, , measurement.pitch);

//For a range of +-2g, we need to divide the raw values by 256, according to the datasheet
    X_out = X_out / rangeDivider;
    Y_out = Y_out / rangeDivider;
    Z_out = Z_out / rangeDivider;

    measurement = nextMeasurement;
}
// TODO: Implement range setting function. Default is 2g
void ADXL344::setRange() {
    return;
}
