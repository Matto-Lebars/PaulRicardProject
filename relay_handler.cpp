/**
 * @file relay_handler.cpp
 * @author Matto LE BARS
 * @date 29/05/2024
 * 
 * @brief This file contains the definitions of the functions to handle the relays on the PPR project.
 * 
 */

#include "relay_handler.h"
#include "ppr_config.h"

void setupRelays() {
    // Set the relay pins as outputs
    pinMode(RELAY_1, OUTPUT);
    pinMode(RELAY_2, OUTPUT);
    pinMode(RELAY_3, OUTPUT);

    // Set relay pins to HIGH to avoid leakage at startup
    digitalWrite(RELAY_1, HIGH);
    digitalWrite(RELAY_2, HIGH);
    digitalWrite(RELAY_3, HIGH);
}

void activateRelay(int relayPin, int delayTime) {
    // Activate the relay for a certain amount of time
    digitalWrite(relayPin, LOW);
    delay(delayTime);
    digitalWrite(relayPin, HIGH);
}
