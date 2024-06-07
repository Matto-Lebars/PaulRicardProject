/**
 * @file ppr_config.h
 * @author Matto LE BARS
 * @date 22/09/2021
 * @brief This file contains the configuration constants for the PPR project.
 * 
 * The constants include pin definitions for the LCD screen, buttons, relays, and sensors.
 * It also includes the refresh rate for the LCD screen, delay for the pumps, and maximum values for recipes and volume.
 * 
 */

#ifndef PPR_CONFIG_H
#define PPR_CONFIG_H

#include <Arduino.h>

/************************************* Pin Definitions *************************************/
// LCD Screen Pins
const uint8_t LCD_RS = 2, LCD_EN = 3, LCD_D4 = 4, LCD_D5 = 5, LCD_D6 = 6, LCD_D7 = 7;
// Button pin definitions
const uint8_t BUTTON_LEFT = A3, BUTTON_RIGHT = A2, BUTTON_SELECT = A1, BUTTON_BACK = A0;
// Relay pin definitions
const uint8_t RELAY_1 = 8, RELAY_2 = 9, RELAY_3 = 10;
// Sensor pin definitions
const uint8_t ULTRA_SONIC_TRIGGER = 13, ULTRA_SONIC_ECHO = 12;

/************************************* Time Constants *************************************/
// Refresh rate for the LCD screen
const uint8_t REFRESH_RATE = 55; // ms
// Debounce delay for the buttons
const uint8_t DEBOUNCE_DELAY = 25; // ms
// Delay in milliseconds to pour 1mL of liquid by Pumps
const uint16_t DELAY_PUMP_1 = 131, DELAY_PUMP_2 = 123, DELAY_PUMP_3 = 145;

/************************************* Sensors Constants *************************************/
// Distance in cm to detect an object for the ultrasonic sensor
const uint8_t ULTRA_SONIC_MIN_RANGE = 3, ULTRA_SONIC_MAX_RANGE = 10; // cm

/************************************* Recipe Constants *************************************/
const uint8_t MAX_RECIPES = 5;
const uint16_t MAX_VOLUME = 100; // Max volume of liquid to mix in mL


#endif // PPR_CONFIG_H