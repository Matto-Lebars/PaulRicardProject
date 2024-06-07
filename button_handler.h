/**
 * @file button_handler.h
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the declarations of the functions to handle the buttons on the PPR project.
 * 
 */

#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H

/**
 * @name setupButtons
 * @brief Setup the button pins.
 * 
 */
void setupButtons();

/**
 * @name isButtonPressed
 * @brief Check if a button is pressed.
 * 
 * @param buttonPin The pin of the button to check.
 * 
 * @return true if the button is pressed, false otherwise.
 */
bool isButtonPressed(int buttonPin);

#endif
