/* ***********************************************************************************************
 * Rotor.h - This header file contains the declarations for the Rotor struct and its functions.
 * A rotor is a rotating component in a system that plays a key role in transferring or converting
 * energy—whether electrical, mechanical, fluid, or aerodynamic. Its motion interacts dynamically
 * with other parts of the system to perform specific functions.
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
 * -----------------------------------------------------------------------------------------------
 * To Do:
 * - Change the rotor length to a dynamic value for more flexibility.
 * - Rearrange the struct members in the construction for better readabitlity and logical order.
 * *********************************************************************************************** */
#ifndef ROTOR_H
#define ROTOR_H

#include <stdbool.h> // For bool data type

// -----------------------------------------------------------------------------------------------
// Define the rotor's length to ensure consistency across the program.
// -----------------------------------------------------------------------------------------------
extern int rotorLength;

// -----------------------------------------------------------------------------------------------
// Rotor - Definition of a rotor with its base properties.
// -----------------------------------------------------------------------------------------------
// @param type as an integer to identify the rotor type.
// @param name as a string to store the rotor's name.
// @param mapping as a string to store the current mapping.
// @param original as a string to store the original mapping for reinitialization.
// @param initialized as a boolean to track if the rotor is fully initialized.
// -----------------------------------------------------------------------------------------------
typedef struct {
    int type;           // Rotor type
    char *name;         // Name of the rotor
    char *mapping;      // Current mapping string
    char *original;     // Original mapping for reinitialization
    bool initialized;   // Tracks if the rotor is fully initialized
} Rotor;

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
void RegRotor(void);

// -----------------------------------------------------------------------------------------------
// SetRotorLength - Set the rotor length to a specific value. This function is used to set the rotor
// length to a specific value. The rotor length is the number of characters in the rotor's mapping.
// -----------------------------------------------------------------------------------------------
// @param lengthIn as an integer to set the rotor length.
// -----------------------------------------------------------------------------------------------  
void SetRotorLength(int lengthIn);

// -----------------------------------------------------------------------------------------------
// DefaultRotor - Because of a declaration problem, this function is a workaround to set the rotor
// in its empty (default) state right after declaration and before initialization to avoid weird
// behavior.
// Program didn't work correctly when variable was created like:
// Rotor smallRotor = {0, NULL, NULL, NULL, false};
// -----------------------------------------------------------------------------------------------
// @param rotor as a pointer to the rotor to be set to default.
// -----------------------------------------------------------------------------------------------
void DefaultRotor(Rotor *rotorInOut);

// -----------------------------------------------------------------------------------------------
// InitRotor - First time initialize a rotor with the given name, mapping, and type. This function
// is acting as a constructor for the rotor struct.
// -----------------------------------------------------------------------------------------------
// @param rotorIn as a pointer to the rotor to be initialized.
// @param nameIn as a string to store the rotor's name.
// @param mappingIn as a string to store the current mapping.
// @param typeIn as an integer to identify the rotor type.
// -----------------------------------------------------------------------------------------------
// To Do: Change order of parameters for better readability.
// -----------------------------------------------------------------------------------------------
void InitRotor(Rotor *rotorInOut, const char *nameIn, const char *mappingIn, int typeIn);

// -----------------------------------------------------------------------------------------------
// ResetRotor - Reset a rotor to its original mapping. Usage is when the rotor is needed to be put
// back to its initial state during the runtime of the program. This function uses the original
// propertye of the struct to restore the mapping inside the rotor.
// -----------------------------------------------------------------------------------------------
// @param rotorIn as a pointer to the rotor to be reset.
// -----------------------------------------------------------------------------------------------
void ResetRotor(Rotor *rotorInOut);

// -----------------------------------------------------------------------------------------------
// FreeRotorMemory - Old school garbage collection. I almost forgot about this, thank you Java and
// C# for making programmer's live easy. Back in c programming we had to do this manually. Not to
// leave dead memory behind down memory lane.
// -----------------------------------------------------------------------------------------------
// @param rotorIn as a pointer to the rotor to free the memory of.
// -----------------------------------------------------------------------------------------------
void FreeRotorMemory(Rotor *rotorInOut);

#endif