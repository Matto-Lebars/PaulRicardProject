/**
 * @file relay_handler.h
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the declarations of the functions to handle the relays on the PPR project.
 *  
 */

#ifndef RELAY_HANDLER_H
#define RELAY_HANDLER_H

/**
 * @name setupRelays
 * @brief Setup the relay pins.
 * 
 */
void setupRelays();

/**
 * @name activateRelay
 * @brief Activate a relay for a certain amount of time.
 * 
 * @param relayPin The pin of the relay to activate.
 * @param delayTime The time in ms to activate the relay.
 * 
 */
void activateRelay(int relayPin, int delayTime);

#endif
