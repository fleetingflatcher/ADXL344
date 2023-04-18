//
// Created by corwin on 4/5/2023.
//

typedef struct {
	unsigned int value : 4;
} int4_t;

#include <stdint.h>
#include <Wire.h>
#include <Arduino.h>

#include "raw_measurement.h"
#include "filtered_measurement.h"

#ifndef ADXL344_H
#define ADXL344_H

enum ADXL344_DATA_RATE {
    ADXL_FL_VSLOW = 0x05, // Corresponds to 3.13 Hz
    ADXL_FL_SLOW  = 0x07, // Corresponds to 12.5 Hz
    ADXL_FL_FAST  = 0x09,   // Corresponds to 50.0 Hz
	ADXL_FL_DEFAULT = 0x0A // Corresponds to 100.0 Hz
};
enum ADXL344_FIFO_MODE {
  ADXL344_FIFO_BYPASS = 0,
  ADXL344_FIFO_FIFO,
  ADXL344_FIFO_STREAM,
  ADXL344_FIFO_TRIGGER  
};

class ADXL344 {
public :
	ADXL344();
    void init() ;

	ADXL344_DATA_RATE configGet_DataRate();
	int8_t configGet_OffsetX();
	int8_t configGet_OffsetY();
	int8_t configGet_OffsetZ();

	void configSet_manualCalibration();
	void configSet_Offsets(int8_t x, int8_t y, int8_t z);
    void configSet_OffsetX(int8_t x);
    void configSet_OffsetY(int8_t y);
    void configSet_OffsetZ(int8_t z);
	void configSet_DataRate(int4_t freq);
	void configSet_FIFOMode(ADXL344_FIFO_MODE);
	void configSet_2gResolution();
    
	FilteredMeasurement get() { return measurement; }
	void read();
    void flushFilter();
	void zeroOut(int numSamples);

private:
    FilteredMeasurement measurement;
    int rangeDivider = 256;
    const int ADDRESS = 0x53; // The adxl344 sensor I^2C address

	
};

#endif //ADXL344_H