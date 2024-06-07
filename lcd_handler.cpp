/**
 * @file lcd_handler.cpp
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the functions to handle the LCD screen on the PPR project.
 * 
*/

#include <LiquidCrystal.h>

#include "lcd_handler.h"
#include "ppr_config.h"

// Initialize the LiquidCrystal object
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

const uint8_t COLS = 16;
const uint8_t ROWS = 2;

void setupLCD() {
    lcd.begin(COLS, ROWS);
}

void displayWelcomeMessage() {
    lcd.print("Welcome!");
    delay(1000);
    lcd.clear();
}

void lcdClearRow(uint8_t row) {
    lcd.setCursor(0, row);
    lcd.print("                ");
    lcd.setCursor(0, row);
}

void lcdClear() {
    lcd.clear();
}

void updateLineLCD(uint8_t row, const char* line) {
    lcdClearRow(row);
    lcd.print(line);
    delay(REFRESH_RATE);
}

void updateLCD(const char* line1, const char* line2) {
    lcdClearRow(0);

    // Center the text on the first line
    uint8_t padding = (COLS - strlen(line1)) / 2;
    for (uint8_t i = 0; i < padding; i++) {
        lcd.print(" ");
    }

    lcd.print(line1);
    lcdClearRow(1);
    lcd.print(line2);
    delay(REFRESH_RATE);
}

void updateLCD(const char* line1, const Recipe &recipe) {
    lcdClearRow(0);

    // Center the text on the first line
    uint8_t padding = (COLS - strlen(line1)) / 2;
    for (uint8_t i = 0; i < padding; i++) {
        lcd.print(" ");
    }

    lcd.print(line1);
    
    lcdClearRow(1);
    lcd.print("1:");
    lcd.print(recipe.liquid1);

    lcd.print(" 2:");
    lcd.print(recipe.liquid2);

    lcd.print(" 3:");
    lcd.print(recipe.liquid3);
    delay(REFRESH_RATE);
}
