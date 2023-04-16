//
// Created by corwin on 4/5/2023.
//

#ifndef ADXL344_RAW_MEASUREMENT_H
#define ADXL344_RAW_MEASUREMENT_H

typedef short int int16;

class raw_measurement {
    // TODO: Implement roll, pitch fields and calculations. Constructor can handle all of this.
public:
    // TODO: Change signature to include two floats, previous roll & pitch for implementation of IIR low-pass filter
    raw_measurement(int16 X, int16 Y, int16 Z);

    int16 X() ;
    int16 Y() ;
    int16 Z() ;
    int16 T() ;
    int16 P() ;

private:
    int16 X_value;
    int16 Y_value;
    int16 Z_value;

    int16 theta_value;
    int16 phi_value;

    bool X_read;    // These variables will be set to true if the axis of the measurement is "old"
    bool Y_read;    // eg. Accelerometer::takeNewReading() sets all to false
    bool Z_read;    // eg. Accelerometer::readZ() sets z_read to true
    bool T_read;
    bool P_read;

    float calculate_roll();
};

#endif //ADXL344_RAW_MEASUREMENT_H
