//
// Created by corwin on 4/5/2023.
//

#ifndef MEASUREMENT_H
#define MEASUREMENT_H

typedef short int int16;

class Measurement {
    // TODO: Implement roll, pitch fields and calculations. Constructor can handle all of this.
public:
    // TODO: Change signature to include two floats, previous roll & pitch for implementation of IIR low-pass filter
    Measurement(int16 X, int16 Y, int16 Z);

    int16 X() ;
    int16 Y() ;
    int16 Z() ;


private:
    int16 X_value;
    int16 Y_value;
    int16 Z_value;


    bool X_read;    // These variables will be set to true if the axis of the measurement is "old"
    bool Y_read;    // eg. Accelerometer::takeNewReading() sets all to false
    bool Z_read;    // eg. Accelerometer::readZ() sets z_read to true
};

#endif //MEASUREMENT_H
