/**
 * @file PaulRicardProject.ino
 * @author Matto LE BARS
 * @date 22/09/2021
 * @brief This file contains the main setup and loop functions for the PPR project.
 * 
 */

#include "ppr_config.h"
#include "lcd_handler.h"
#include "button_handler.h"
#include "relay_handler.h"
#include "sensor_handler.h"
#include "user_interface.h"


void setup() {
  // Setup the LCD
  setupLCD();

  // Setup the buttons
  setupButtons();

  // Setup the relays
  setupRelays();

  // Setup sensors
  setupUltraSonicSensor();

  // Display the welcome message
  displayWelcomeMessage();

  // Load the recipes from the EEPROM
  loadRecipes();
}

void loop() {
  // Main menu UI
  mainMenuUI();
}
