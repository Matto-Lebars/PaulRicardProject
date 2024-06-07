/**
 * @file button_handler.cpp
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the functions to handle the buttons on the PPR project.
 * 
 */

#include "button_handler.h"
#include "ppr_config.h"

void setupButtons() {
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_SELECT, INPUT_PULLUP);
    pinMode(BUTTON_BACK, INPUT_PULLUP);
}

bool isButtonPressed(int buttonPin) {
    // Debounce delay
    delay(DEBOUNCE_DELAY);
    return !digitalRead(buttonPin);
}
