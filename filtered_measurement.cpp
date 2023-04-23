//
// Created by corwin on 4/15/2023.
//

#include "filtered_measurement.h"

FilteredMeasurement::FilteredMeasurement() {}

FilteredMeasurement::FilteredMeasurement(RawMeasurement next, FilteredMeasurement prev) {
	// RawMeasurement has ints; so convert to float
	float newX, newY, newZ;
	newX = (float)next.X();
	newY = (float)next.Y();
	newZ = (float)next.Z();
	// Average the two floats
	X_value = (newX + prev.X()) / 2;
	Y_value = (newY + prev.Y()) / 2;
	Z_value = (newZ + prev.Z()) / 2;
	pitch_value = (next.pitch() + prev.pitch()) / 2;
	roll_value = (next.roll() + prev.roll()) / 2;
}
