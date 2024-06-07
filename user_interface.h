/**
 * @file user_interface.h
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the declarations of the functions to handle the user interface on the PPR project.
 * 
 */

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "ppr_config.h"

/**
 * @name mainMenuUI
 * @brief Main menu UI
 * @details This function allows the user to navigate the main menu. He can choose between mixing colors and viewing recipes.
 * 
 */
void mainMenuUI();



/**
 * @name recipeMenuUI
 * @brief Recipe menu UI
 * @details This function allows the user to navigate the recipes.
 */
void recipeMenuUI();

/**
 * @name viewRecipeUI
 * @brief Create recipe UI
 * @details This function allows the user to create or modify a recipe.
 */
void modifyRecipeUI();

/**
 * @name viewRecipeUI
 * @brief Input a volume UI
 * @details This function allows the user to input a volume for a liquid.
 * @param volume The volume to input
 * @param totalVolume The total of liquid already input
 * @return The volume input by the user
 */
int inputVolumeUI(const char* liquid, uint16_t volume, uint16_t totalVolume);

/**
 * @name isModifyRequidedUI
 * @brief Check if the user wants to modify a recipe
 * @details This function allows the user to choose if he wants to modify a recipe.
 * @return True if the user wants to modify a recipe, false otherwise
 */
bool isModifyRequidedUI();

/**
 * @name mixLiquidUI
 * @brief Mix liquid UI
 * @details This function displays information about the liquid mixing.
 */
void mixLiquidUI();

#endif