/**
 * @file user_interface.cpp
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the definitions of the functions to handle the user interface on the PPR project.
 * 
 */

#include "user_interface.h"

#include "lcd_handler.h"
#include "button_handler.h"
#include "relay_handler.h"
#include "sensor_handler.h"
#include "recipe.h"

int8_t currentState = 0;
int8_t menuItem = 0;

extern Recipe recipes[MAX_RECIPES];
uint8_t currentRecipe = 0;

const uint8_t MENU_ITEMS = 2; // Number of items in the main menu

void mainMenuUI() {
  // Display the main menu

  const char *menuItems[MENU_ITEMS] = {
    ">Mix Colors",
    ">View Recipes"
  };

  switch (currentState) {

    case 0: // Main menu
      updateLCD("Main Menu", menuItems[menuItem]); // Update the LCD with the main menu
      
      if (isButtonPressed(BUTTON_LEFT)) {
        menuItem--;
        if (menuItem < 0) menuItem = MENU_ITEMS - 1;
      }

      if (isButtonPressed(BUTTON_RIGHT)) {
        menuItem++;
        if (menuItem > MENU_ITEMS - 1) menuItem = 0;
      }
      
      if (isButtonPressed(BUTTON_SELECT)) {
        currentState = menuItem + 1; // Change the state to the selected menu item
      }
      break;

    case 1: // Create Recipe
      mixLiquidUI();
      currentState = 0; // Return to main menu after creating recipe
      break;

    case 2: // Mix Colors
      recipeMenuUI();
      currentState = 0; // Return to main menu after mixing colors
      break;
  }
}

void recipeMenuUI() {
    // Display the recipe menu

    int8_t recipeIndex = currentRecipe;

    while (true) {
        String recipeName = "Recipe " + String(recipeIndex + 1);
        updateLCD(recipeName.c_str(), recipes[recipeIndex]);

        if (isButtonPressed(BUTTON_LEFT)) {
            recipeIndex--;
            if (recipeIndex < 0) recipeIndex = MAX_RECIPES - 1;
        }

        if (isButtonPressed(BUTTON_RIGHT)) {
            recipeIndex++;
            if (recipeIndex > MAX_RECIPES - 1) recipeIndex = 0;
        }

        if (isButtonPressed(BUTTON_SELECT)) {
            currentRecipe = recipeIndex;
            if (isModifyRequidedUI()) { // Check if the user wants to modify the recipe
                modifyRecipeUI();
            } else {
                updateLCD("Recipe Selected!", "");
                delay(1000);
            }
            break;
        }

        if (isButtonPressed(BUTTON_BACK)) {
            lcdClear();
            break;
        }
    }
}

void modifyRecipeUI() {
    // Display the modify recipe menu

    uint16_t liquid1 = recipes[currentRecipe].liquid1, liquid2 = recipes[currentRecipe].liquid2, liquid3 = recipes[currentRecipe].liquid3;

    // Input the volume for the first liquid
    liquid1 = inputVolumeUI("Liquid 1:", liquid1, 0);

    // Input the volume for the second liquid
    liquid2 = inputVolumeUI("Liquid 2:", liquid2, liquid1);

    // Input the volume for the third liquid
    liquid3 = inputVolumeUI("Liquid 3:", liquid3, liquid1 + liquid2);

    recipes[currentRecipe] = {liquid1, liquid2, liquid3};
    saveRecipes();

    updateLCD("Recipe Saved!", "& Selected!");
    delay(1000);
}

bool isModifyRequidedUI() {
    // Ask the user if they want to modify a recipe

    bool choiceIndex = false;

    const char *choices[2] = {
        ">No -Yes",
        "-No >Yes"
    };

    while (true) {
        updateLCD("Modify Recipe?", choices[choiceIndex]);

        if (isButtonPressed(BUTTON_LEFT)) {
            choiceIndex = !choiceIndex;
        }

        if (isButtonPressed(BUTTON_RIGHT)) {
            choiceIndex = !choiceIndex;
        }

        if (isButtonPressed(BUTTON_SELECT)) {
            return choiceIndex;
        }
    }
}

int inputVolumeUI(const char* liquid, uint16_t volume, uint16_t totalVolume) {
    // Input the volume for a liquid

    updateLineLCD(0, liquid);
    
    if ((volume + totalVolume) > MAX_VOLUME) {
        volume = MAX_VOLUME - totalVolume;
    }
    

    while (true) {
        updateLineLCD(1, String(volume).c_str());

        if (isButtonPressed(BUTTON_LEFT)) {
            volume--;
            if (volume > MAX_VOLUME - totalVolume) volume = MAX_VOLUME - totalVolume;
        }

        if (isButtonPressed(BUTTON_RIGHT)) {
            volume++;
            if (volume > MAX_VOLUME - totalVolume) volume = 0;
        }

        if (isButtonPressed(BUTTON_SELECT)) {
            return volume;
        }
    }
}

void mixLiquidUI() {
    // Launch Liquid Mixing Logic and UI

    if (!isObjectDetectedInRange())
    {
        updateLCD("Can't Mix!", "No Cup Detected");
        delay(2000);
        return;
    }   

    updateLCD(("Mix Recipe " + String(currentRecipe + 1)).c_str(), "");

    // Pour the first liquid
    updateLineLCD(2, ("L1 :" + String(recipes[currentRecipe].liquid1) + "mL").c_str());
    activateRelay(RELAY_1, recipes[currentRecipe].liquid1 * DELAY_PUMP_1);

    // Pour the second liquid
    updateLineLCD(3, ("L2 :" + String(recipes[currentRecipe].liquid2) + "mL").c_str());
    activateRelay(RELAY_2, recipes[currentRecipe].liquid2 * DELAY_PUMP_2);

    // Pour the third liquid
    updateLineLCD(4, ("L3 :" + String(recipes[currentRecipe].liquid3) + "mL").c_str());
    activateRelay(RELAY_3, recipes[currentRecipe].liquid3 * DELAY_PUMP_3);

    updateLCD("Mixing Done!", "");
    delay(2000);
}