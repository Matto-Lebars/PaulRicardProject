/**
 * @file sensor_handler.cpp
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the definitions of the functions to handle the ultrasonic sensor on the PPR project.
 */

#include "sensor_handler.h"
#include "ppr_config.h"

void setupUltraSonicSensor() {
    // Setup the ultrasonic sensor
    pinMode(ULTRA_SONIC_TRIGGER, OUTPUT); // Set the trigger pin as output
    pinMode(ULTRA_SONIC_ECHO, INPUT);  // Set the echo pin as input
}

// Function to detect object within a specified range using ultrasonic sensor
bool isObjectDetectedInRange(int minRange, int maxRange) {
    long duration;
    int distance;

    // Clear the trigger pin
    digitalWrite(ULTRA_SONIC_TRIGGER, LOW);
    delayMicroseconds(2);

    // Set the trigger pin HIGH for 10 microseconds
    digitalWrite(ULTRA_SONIC_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRA_SONIC_TRIGGER, LOW);

    // Read the echo pin, pulseIn returns the duration (time in microseconds) of the pulse
    duration = pulseIn(ULTRA_SONIC_ECHO, HIGH);

    // Calculate the distance (duration / 2 because the signal goes to the object and back)
    // Speed of sound is 34300 cm/s or 29.1 microseconds per cm
    distance = duration * 0.034 / 2;

    // Return true if distance is within the specified range, otherwise false
    return (distance >= minRange && distance <= maxRange);
}
