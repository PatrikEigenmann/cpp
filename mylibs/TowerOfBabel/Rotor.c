/* ***********************************************************************************************
 * Rotor.c - This code file contains the function for the Rotor struct so the rotor can operate in
 * its core functions. A rotor is a rotating component in a system that plays a key role in
 * transferring or converting energy—whether electrical, mechanical, fluid, or aerodynamic.
 * Its motion interacts dynamically with other parts of the system to perform specific functions.
 *
 * Applications:
 * - Energy Transfer: Rotors in motors, generators, and turbines 
 *   convert energy between forms, like electrical to mechanical.
 * - Motion and Stability: Rotors in helicopters and gyroscopes 
 *   generate controlled movement and stability.
 * - Flow Management: Rotors in pumps and compressors regulate the
 *   flow of fluids or gases efficiently.
 * - Cryptography: Rotors are the driving force behind various encryption machines, like the Enigma.
 *
 * At its core, a rotor is defined by its ability to spin and interact with other elements to
 * facilitate motion, energy transfer, or system management.
 * -----------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -----------------------------------------------------------------------------------------------
 * Change Log:
 * Mon 2025-03-24 File created.                                                     Version: 00.01
 * Thu 2025-03-27 Replaced the ROTOR_LENGTH with a dynamic value rotorLength.       Version: 00.02
 * -----------------------------------------------------------------------------------------------
 * To Do:
 * - Change the rotor length to a dynamic value for more flexibility.
 * - Rearrange the struct members in the construction for better readabitlity and logical order.
 * *********************************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // For bool data type

#include "Rotor.h"

int rotorLength = -1;

// -----------------------------------------------------------------------------------------------
// setRotorLength - Set the rotor length to a specific value. This function is used to set the rotor
// length to a specific value. The rotor length is the number of characters in the rotor's mapping.
// -----------------------------------------------------------------------------------------------
// @param length as an integer to set the rotor length.
// -----------------------------------------------------------------------------------------------  
void setRotorLength(int length) {
    rotorLength = length;
}

// -----------------------------------------------------------------------------------------------
// defaultRotor - Because of a declaration problem, this function is a workaround to set the rotor
// in its empty (default) state right after declaration and before initialization to avoid weird
// behavior.
// Program didn't work correctly when variable was created like:
// Rotor smallRotor = {0, NULL, NULL, NULL, false};
// -----------------------------------------------------------------------------------------------
// @param rotor as a pointer to the rotor to be set to default.
// -----------------------------------------------------------------------------------------------
void defaultRotor(Rotor *rotor) {
    rotor->name = NULL;
    rotor->mapping = NULL;
    rotor->original = NULL;
    rotor->type = -1;
    rotor->initialized = false;
}

// -----------------------------------------------------------------------------------------------
// initRotor - First time initialize a rotor with the given name, mapping, and type. This function
// is acting as a constructor for the rotor struct.
// -----------------------------------------------------------------------------------------------
// @param rotor as a pointer to the rotor to be initialized.
// @param name as a string to store the rotor's name.
// @param mapping as a string to store the current mapping.
// @param type as an integer to identify the rotor type.
// -----------------------------------------------------------------------------------------------
// To Do: Change order of parameters for better readability.
// -----------------------------------------------------------------------------------------------
void initRotor(Rotor *rotor, const char *name, const char *mapping, int type) {
    

    if(rotorLength == -1) {

        printf("Error: Rotor length not set. Please set the rotor length before initializing the rotor.\n");
        rotorLength = strlen(mapping);
        //return;
    }
    
    rotor->name = malloc(strlen(name) + 1);  // Allocate memory for name
    strcpy(rotor->name, name);              // Copy name to struct

    rotor->mapping = malloc(rotorLength + 1);  // Allocate memory for current mapping
    strcpy(rotor->mapping, mapping);           // Copy mapping to struct

    rotor->original = malloc(rotorLength + 1); // Allocate memory for original mapping
    strcpy(rotor->original, mapping);          // Store original mapping

    rotor->type = type;                        // Assign type
    rotor->initialized = true;                 // Mark rotor as initialized

    //printf("Length of %sRotor mapping: %lu\n", rotor->name, strlen(mapping));
}

// -----------------------------------------------------------------------------------------------
// resetRotor - Reset a rotor to its original mapping. Usage is when the rotor is needed to be put
// back to its initial state during the runtime of the program. This function uses the original
// propertye of the struct to restore the mapping inside the rotor.
// -----------------------------------------------------------------------------------------------
// @param rotor as a pointer to the rotor to be reset.
// -----------------------------------------------------------------------------------------------
void resetRotor(Rotor *rotor) {
    if (!rotor->initialized) {
        printf("Error: Attempted to reset an uninitialized rotor.\n");
        return;
    }

    // Reset the rotor's mapping to its original state
    strcpy(rotor->mapping, rotor->original);

    // Debug print for reinitialization
    //printf("Reset %sRotor: %s\n", rotor->name, rotor->mapping);
}

// -----------------------------------------------------------------------------------------------
// freeRotorMemory - Old school garbage collection. I almost forgot about this, thank you Java and
// C# for making programmer's live easy. Back in c programming we had to do this manually. Not to
// leave dead memory behind down memory lane.
// -----------------------------------------------------------------------------------------------
// @param rotor as a pointer to the rotor to free the memory of.
// -----------------------------------------------------------------------------------------------
void freeRotorMemory(Rotor *rotor) {
    
    if (!rotor->initialized) {
        printf("Warning: Attempted to free an uninitialized rotor (%sRotor).\n", rotor->name ? rotor->name : "Unknown");
        return;
    }

    if (rotor->name) {
        free(rotor->name);
        rotor->name = NULL;
    }
    if (rotor->mapping) {
        free(rotor->mapping);
        rotor->mapping = NULL;
    }
    if (rotor->original) {
        free(rotor->original);
        rotor->original = NULL;
    }
    rotor->initialized = false;

    //printf("Memory freed for %sRotor.\n", rotor->name ? rotor->name : "Unknown");
}