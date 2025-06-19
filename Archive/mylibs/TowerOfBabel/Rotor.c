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
 * Sun 2025-04-06 Register component with its version in the Samael Framework.      Version: 00.03
 * Tue 2025-04-08 Implemented the new Samael naming conventions.                    Version: 00.04
 * Tue 2025-04-08 BugFix: RegisterVersion instead of registerVersion.               Version: 00.05
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

#ifdef _WIN32
    // _-* Window Section *-_
    #include "..\Samael.h"
    #include "..\Samael.TowerOfBabel.h"
#else
    // _-* MacOS/Linux Section *-_
    #include "../Samael.h"
    #include "../Samael.TowerOfBabel.h"
#endif


int rotorLength = -1;

// -------------------------------------------------------------------------------------------
// RegRotor - Automatically registers this component's version information with the versioning
// system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.TowerOfBabel.Rotor.c), which means it will automatically be executed prior to the
// execution of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void RegRotor(void) {
    // Register the component with its version information
    RegisterVersion("Samael.TowerOfBabel", "Rotor", 0, 5);  // BugFix: RegisterVersion instead of registerVersion Version 00.05
}

// -----------------------------------------------------------------------------------------------
// SetRotorLength - Set the rotor length to a specific value. This function is used to set the rotor
// length to a specific value. The rotor length is the number of characters in the rotor's mapping.
// -----------------------------------------------------------------------------------------------
// @param lengthIn as an integer to set the rotor length.
// -----------------------------------------------------------------------------------------------  
void SetRotorLength(int lengthIn) {
    rotorLength = lengthIn;
}

// -----------------------------------------------------------------------------------------------
// DefaultRotor - Because of a declaration problem, this function is a workaround to set the rotor
// in its empty (default) state right after declaration and before initialization to avoid weird
// behavior.
// Program didn't work correctly when variable was created like:
// Rotor smallRotor = {0, NULL, NULL, NULL, false};
// -----------------------------------------------------------------------------------------------
// @param rotorInOut as a pointer to the rotor to be set to default.
// -----------------------------------------------------------------------------------------------
void defaultRotor(Rotor *rotorInOut) {
    rotorInOut->name = NULL;
    rotorInOut->mapping = NULL;
    rotorInOut->original = NULL;
    rotorInOut->type = -1;
    rotorInOut->initialized = false;
}

// -----------------------------------------------------------------------------------------------
// InitRotor - First time initialize a rotor with the given name, mapping, and type. This function
// is acting as a constructor for the rotor struct.
// -----------------------------------------------------------------------------------------------
// @param rotorInOut as a pointer to the rotor to be initialized.
// @param nameIn as a string to store the rotor's name.
// @param mappingIn as a string to store the current mapping.
// @param typeIn as an integer to identify the rotor type.
// -----------------------------------------------------------------------------------------------
// To Do: Change order of parameters for better readability.
// -----------------------------------------------------------------------------------------------
void InitRotor(Rotor *rotorInOut, const char *nameIn, const char *mappingIn, int typeIn) {
    
    if(rotorLength == -1) {
        // If rotorLength is not set, print an error message and set it dynamically
        printf("Error: Rotor length not set. Please set the rotor length before initializing the rotor.\n");
        rotorLength = strlen(mappingIn);
    }
    
    rotorInOut->name = malloc(strlen(nameIn) + 1);  // Allocate memory for name
    strcpy(rotorInOut->name, nameIn);               // Copy name to struct

    rotorInOut->mapping = malloc(rotorLength + 1);  // Allocate memory for current mapping
    strcpy(rotorInOut->mapping, mappingIn);         // Copy mapping to struct

    rotorInOut->original = malloc(rotorLength + 1); // Allocate memory for original mapping
    strcpy(rotorInOut->original, mappingIn);        // Store original mapping

    rotorInOut->type = typeIn;                      // Assign type
    rotorInOut->initialized = true;                 // Mark rotor as initialized

}

// -----------------------------------------------------------------------------------------------
// ResetRotor - Reset a rotor to its original mapping. Usage is when the rotor is needed to be put
// back to its initial state during the runtime of the program. This function uses the original
// propertye of the struct to restore the mapping inside the rotor.
// -----------------------------------------------------------------------------------------------
// @param rotorInOut as a pointer to the rotor to be reset.
// -----------------------------------------------------------------------------------------------
void ResetRotor(Rotor *rotorInOut) {
    
    // Check if the rotor is initialized before attempting to reset
    if (!rotorInOut->initialized) {
        printf("Error: Attempted to reset an uninitialized rotor.\n");  // Show an error message
        return;                                                         // Exit the function
    }

    // Reset the rotor's mapping to its original state
    strcpy(rotorInOut->mapping, rotorInOut->original);
}

// -----------------------------------------------------------------------------------------------
// FreeRotorMemory - Old school garbage collection. I almost forgot about this, thank you Java and
// C# for making programmer's live easy. Back in c programming we had to do this manually. Not to
// leave dead memory behind down memory lane.
// -----------------------------------------------------------------------------------------------
// @param rotor as a pointer to the rotor to free the memory of.
// -----------------------------------------------------------------------------------------------
void FreeRotorMemory(Rotor *rotorInOut) {
    
    // Check if the rotor is initialized before attempting to free memory
    if (!rotorInOut->initialized) {
        // Show a warning message if the rotor is not initialized
        printf("Warning: Attempted to free an uninitialized rotor (%sRotor).\n", rotorInOut->name ? rotorInOut->name : "Unknown");
        return; // Exit the function
    }

    // Free the allocated memory for the rotor's name.
    if (rotorInOut->name) {
        free(rotorInOut->name);
        rotorInOut->name = NULL;
    }

    // Free the allocated memory for the rotor's mapping.
    if (rotorInOut->mapping) {
        free(rotorInOut->mapping);
        rotorInOut->mapping = NULL;
    }

    // Free the allocated memory for the rotor's original mapping.
    if (rotorInOut->original) {
        free(rotorInOut->original);
        rotorInOut->original = NULL;
    }

    // Set the rotor's type to -1 to indicate it is no longer valid
    rotorInOut->initialized = false;
}