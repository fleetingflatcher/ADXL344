//
// Created by corwin on 4/5/2023.
//

#include "ADXL344.h"

ADXL344::ADXL344() {}

// TODO: read through this; make sure it makes sense.
// TODO: More than that, make sure there are no config registers we're missing.
void ADXL344::init() {
    Wire.begin(); // Initiate the Wire library

    // Start measuring. Set link bit.
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x2D); 
    Wire.write(0x28);
    Wire.endTransmission();
    delay(10);

    configSet_Offsets(4,4,-6);

    /*
    // Set up activity/inactivity monitoring
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x27);
    Wire.write(0x77);
    Wire.endTransmission();

    // Set activity threshold
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x24);
    Wire.write(0xFF);
    Wire.endTransmission();

    // Set inactivity threshold
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x25);
    Wire.write(0x01);
    Wire.endTransmission();

    // Set activity timeout
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x26);
    Wire.write(0x01);
    Wire.endTransmission();
    */
    // Enable interrupts
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x2E);
    Wire.write(0x98);
    Wire.endTransmission();

	//set2gResolution();
}

void ADXL344::configSet_manualCalibration() {
	configSet_Offsets(-10, 80, -100);
}

void ADXL344::flushFilter() { measurement = FilteredMeasurement(); }


void ADXL344::read() {
	Wire.beginTransmission(ADDRESS);
	Wire.write(0x32);
	Wire.endTransmission(false);
	Wire.requestFrom(ADDRESS, 6, true);	
	int16_t x = ( Wire.read() | Wire.read() << 8); // X-axis value
	int16_t y = ( Wire.read() | Wire.read() << 8); // Y-axis value
	int16_t z = ( Wire.read() | Wire.read() << 8); // Z-axis value	
	RawMeasurement raw = RawMeasurement(x, y, z);
	measurement = FilteredMeasurement(raw, measurement);
}

void ADXL344::configSet_2gResolution() {
	Wire.beginTransmission(ADDRESS);
	Wire.write(0x31);
	Wire.requestFrom(ADDRESS, 1, true);
	uint8_t DAT_FMT_REG = Wire.read();
	Wire.endTransmission();

	DAT_FMT_REG &= ~0x0B;

	Wire.beginTransmission(ADDRESS);
	Wire.write(0x31);
	Wire.write(DAT_FMT_REG);
	Wire.endTransmission();
	delay(5);
}

void ADXL344::configSet_DataRate(ADXL344_DATA_RATE freq) {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x2C);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDRESS, 1, true);

    int8_t BW_RATE_REG = Wire.read();
    BW_RATE_REG &= ~0x0F;
    BW_RATE_REG |=  freq;

    Wire.beginTransmission(ADDRESS);
    Wire.write(0x2C);
    Wire.write(BW_RATE_REG);
    Wire.endTransmission();
    delay(5);
}

void ADXL344::configSet_FIFOMode(ADXL344_FIFO_MODE mode) {
  Wire.beginTransmission(ADDRESS);
  Wire.write(0x38);
  Wire.write(mode);
  Wire.endTransmission();
  delay(5);
}

void ADXL344::configSet_Offsets(int8_t x, int8_t y, int8_t z) {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x1E);
    Wire.write(x);
    Wire.endTransmission();

	Wire.beginTransmission(ADDRESS);
    Wire.write(0x1F);
    Wire.write(y);
    Wire.endTransmission();

	Wire.beginTransmission(ADDRESS);
    Wire.write(0x20);
    Wire.write(z);
    Wire.endTransmission();

    delay(5);
}

void ADXL344::configSet_OffsetX(int8_t offset) {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x1E);
    Wire.write(offset);
    Wire.endTransmission();
    delay(5);
}
void ADXL344::configSet_OffsetY(int8_t offset) {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x1F);
    Wire.write(offset);
    Wire.endTransmission();
    delay(5);
}
void ADXL344::configSet_OffsetZ(int8_t offset) {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x20);
    Wire.write(offset);
    Wire.endTransmission();
    delay(5);
}
int8_t ADXL344::configGet_OffsetX() {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x1E);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDRESS, 1, true);
    int8_t val = Wire.read();
    return val;
}
int8_t ADXL344::configGet_OffsetY() {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x1F);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDRESS, 1, true);
    int8_t val = Wire.read();
    return val;
}
int8_t ADXL344::configGet_OffsetZ() {
    Wire.beginTransmission(ADDRESS);
    Wire.write(0x20);
    Wire.endTransmission(false);
    Wire.requestFrom(ADDRESS, 1, true);
    int8_t val = Wire.read();
    return val;
}