/**
 * @file lcd_handler.h
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the declarations of the functions to handle the LCD on the PPR project.
 * 
 */

#ifndef LCD_HANDLER_H
#define LCD_HANDLER_H

#include "recipe.h"

/**
 * @name setupLCD
 * @brief Setup the LCD screen.
 * 
 */
void setupLCD();

/**
 * @name displayWelcomeMessage
 * @brief Display the welcome message on the LCD screen.
 * 
 * This function displays the welcome message on the LCD screen.
 * ONLY USED AT THE STARTUP.
 * 
 */
void displayWelcomeMessage();

/**
 * @name lcdClearRow
 * @brief Clear a row on the LCD screen.
 * 
 * @param row The row to clear.
 * 
 */
void lcdClearRow(uint8_t row);

/**
 * @name lcdClear
 * @brief Clear the LCD screen.
 * 
 */
void lcdClear();

/**
 * @name updateLineLCD
 * @brief Update a line on the LCD screen.
 * 
 * @param row The line to update.
 * @param line The message to display.
 * 
 */
void updateLineLCD(uint8_t row, const char* line);

/**
 * @name updateLCD
 * @brief Update the LCD screen.
 * 
 * @param line1 The first line to display.
 * @param line2 The second line to display.
 * 
 */
void updateLCD(const char* line1, const char* line2);

/**
 * @name updateLCD
 * @brief Update the LCD screen with a recipe.
 * 
 * @param line1 The first line to display.
 * @param recipe The recipe to display.
 * 
 */
void updateLCD(const char* line1, const Recipe &recipe);

#endif
