//
// Created by corwin on 4/15/2023.
//

#ifndef ADXL344_FILTERED_MEASUREMENT_H
#define ADXL344_FILTERED_MEASUREMENT_H

#include "raw_measurement.h"

class FilteredMeasurement {
public:
	FilteredMeasurement();
    FilteredMeasurement(RawMeasurement next, FilteredMeasurement prev);

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
};


#endif //ADXL344_FILTERED_MEASUREMENT_H
