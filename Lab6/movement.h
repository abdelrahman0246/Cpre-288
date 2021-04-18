/*
 * movement.h
 *
 *  Created on: Feb 9, 2021
 *      Author: bjheinen
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "open_interface.h"

double move_forward(oi_t *sensor_data, double distance_mm);
double turn_left(oi_t *sensor_data, double degrees);
double turn_right(oi_t *sensor_data, double degrees);
double move_backwards(oi_t *sensor_data, double distance_mm);

#endif /* MOVEMENT_H_ */
