//
// Created by corwin on 4/5/2023.
//

#ifndef ADXL344_RAW_MEASUREMENT_H
#define ADXL344_RAW_MEASUREMENT_H

#include <stdint.h>

class RawMeasurement {
public:
	RawMeasurement();
    RawMeasurement(int16_t X, int16_t Y, int16_t Z);

    const int16_t X()       { return X_value; }
    const int16_t Y()       { return Y_value; }
    const int16_t Z()       { return Z_value; }
    const float pitch()   { return pitch_value; }   // Theta
    const float roll()    { return roll_value; }    // Phi

private:
    int16_t X_value;
    int16_t Y_value;
    int16_t Z_value;
    float pitch_value;
    float roll_value;

	float calculateRoll();
	float calculatePitch() ;
};

#endif //ADXL344_RAW_MEASUREMENT_H
