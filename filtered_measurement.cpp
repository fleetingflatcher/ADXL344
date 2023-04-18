//
// Created by corwin on 4/15/2023.
//

#include "filtered_measurement.h"

FilteredMeasurement::FilteredMeasurement() {}

FilteredMeasurement::FilteredMeasurement(RawMeasurement next, FilteredMeasurement prev) {
	X_value = (next.X() + prev.X()) / 2;
	Y_value = (next.Y() + prev.Y()) / 2;
	Z_value = (next.Z() + prev.Z()) / 2;
	pitch_value = (next.pitch() + prev.pitch()) / 2;
	roll_value = (next.roll() + prev.roll()) / 2;
}
