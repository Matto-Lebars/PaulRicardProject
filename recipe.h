/**
 * @file recipe.h
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the declarations of the functions to handle the recipes on the PPR project.
 * 
 */
#ifndef RECIPE_H
#define RECIPE_H

struct Recipe {
    uint16_t liquid1;
    uint16_t liquid2;
    uint16_t liquid3;
};

/**
 * @name loadRecipes
 * @brief Load the recipes from the EEPROM.
 * 
 * @details This function loads the recipes from the EEPROM and stores them in the recipes array.
 */
void loadRecipes();

/**
 * @name saveRecipes
 * @brief Save the recipes to the EEPROM.
 * 
 */
void saveRecipes();

#endif
