/**
 * @file recipe.cpp
 * @author Matto LE BARS
 * @date 05/06/2024
 * @brief This file contains the definitions of the functions to handle the recipes on the PPR project.
 * 
 * The recipes are stored in the EEPROM and can be accessed by the user to create, modify, and delete recipes.
 * The recipes are stored in a struct that contains the name of the recipe and the volume of each liquid to mix.
 * 
 */

#include <EEPROM.h>

#include "recipe.h"
#include "ppr_config.h"

Recipe recipes[MAX_RECIPES];

void loadRecipes() {
  for (int i = 0; i < MAX_RECIPES; i++) {
    EEPROM.get(i * sizeof(Recipe), recipes[i]);
  }
}

void saveRecipes() {
  for (int i = 0; i < MAX_RECIPES; i++) {
    EEPROM.put(i * sizeof(Recipe), recipes[i]);
  }
  EEPROM.put(MAX_RECIPES * sizeof(Recipe), MAX_RECIPES);
}
