/**
 * @file sensor_handler.h
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the declarations of the functions to handle the ultrasonic sensor on the PPR project.
 * 
 */

#ifndef SENSOR_HANDLER_H
#define SENSOR_HANDLER_H

#include "ppr_config.h"

/**
 * @name setupUltraSonicSensor
 * @brief Setup the ultrasonic sensor pins.
 * 
 */
void setupUltraSonicSensor();

/**
 * @name isObjectDetectedInRange
 * @brief Check if an object is detected in the specified range.
 * 
 * @param minRange The minimum range in cm to detect an object.
 * @param maxRange The maximum range in cm to detect an object.
 * 
 * @return true if an object is detected in the specified range, false otherwise.
 */
bool isObjectDetectedInRange(int minRange = ULTRA_SONIC_MIN_RANGE, int maxRange = ULTRA_SONIC_MAX_RANGE);

#endif