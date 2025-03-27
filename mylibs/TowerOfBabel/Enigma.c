/* ***********************************************************************************************
 * Enigma.c - This c program is an attempt to emulate the Enigma cipher machine used in World War II.
 * The Enigma cipher machine was originally developed and widely used in the early to mid-20th
 * century to protect commercial, diplomatic, and military communication. Nazi Germany extensively
 * employed it during World War II, across all branches of their military. The machine was considered
 * so secure that it was used to encipher even the most top-secret messages.
 *
 * The Enigma machine features an electromechanical rotor mechanism that scrambles characters. In
 * typical operation, one person enters text on the Enigma's keyboard, while another records the
 * corresponding illuminated letters above the keyboard. If plaintext is entered, the output is
 * ciphertext; entering ciphertext transforms it back into plaintext. The rotor mechanism
 * dynamically changes the electrical connections between keys and lights with each keypress.
 *
 * The security of the system relied on specific machine settings, generally changed daily according
 * to secret key lists distributed in advance, and settings adjusted for each message. The
 * receiving station needed to use the exact same settings as the transmitting station to
 * successfully decrypt a message.
 *
 * Despite its complexity and high level of security, the Enigma machine was not unbreakable.
 * Polish mathematician Marian Rejewski and his team were the first to break the code in the
 * early 1930s. During World War II, the British established the secret code-breaking unit
 * known as Ultra, led by mathematician Alan M. Turing. Intelligence gleaned from decrypting
 * Enigma-encoded messages significantly contributed to the Allied victories.
 *
 * This program is a showcase of the capabilities of the Enigma machine. It demonstrates
 * how messages can be encrypted and decrypted using the principles of rotor-based
 * cryptography, offering a simplified example of its ingenious design.
 * -----------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -----------------------------------------------------------------------------------------------
 * Version Control:
 * Tue 2025-03-25 File created.                                                     Version: 00.01
 * Thu 2025-03-27 Defined ROTOR_LENTGH in enigma.h, because it is enigma specific.  Version: 00.02
 * Thu 2025-03-27 setRotorLength in powerUp before initializing the rotors.         Version: 00.03
 * ***********************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // For bool data type

#include "Rotor.h"
#include "Enigma.h"

// -----------------------------------------------------------------------------------------------
// Definition of the three rotors used in the Enigma machine. The small, medium, and large rotor
// are the core components of the Enigma machine. Each rotor has a specific mapping that is used
// to encrypt and decrypt messages. The rotor struct is defined in Rotor.h.
// -----------------------------------------------------------------------------------------------
Rotor smallRotor, mediumRotor, largeRotor;

// -----------------------------------------------------------------------------------------------
// powerUp - This is truly a magical moment. I bet when german engineers first time powered up the
// Enigma machine, their eyes were sparkling like little kids on Christmas. I hope you can capture
// the same magical moment when you include my Enigma.h and plug the beast in. Power it up baby.
// There is something seriously satisfying just writing the word "powerUp". Ignite your cipher machine
// and let the magic begin.
// -----------------------------------------------------------------------------------------------
void powerUp() {
    
    if (rotorLength == -1) {
        setRotorLength(ROTOR_LENGTH);
        // printf("Error: Rotor length not set. Please set the rotor length before powering up the Enigma machine.\n");
        //return;
    }
    
    initRotor(&smallRotor,  "Small",  " 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~", SMALL);
    initRotor(&mediumRotor, "Medium", "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~abcdefghijklmnopqrstuvwxyz", MEDIUM);
    initRotor(&largeRotor,  "Large",  "89./:;<=>?@[\\]^_`{|}~ABCD4567LMNOghijklmnopqrEFGHIJK0123stuvwxyz!\"#$%&'()*+,-PQRST UVWXYZabcdef", LARGE);
}

// -----------------------------------------------------------------------------------------------
// startFromScratch - Reset the Enigma machine to its original state. This function is used to
// reset the rotor mappings to their original state. It is used to start the Enigma machine from
// scratch, ensuring that the rotor mappings are in their initial configuration.
// -----------------------------------------------------------------------------------------------
void startFromScratch() {
    resetRotor(&smallRotor);
    resetRotor(&mediumRotor);
    resetRotor(&largeRotor);
    
    //printf("Enigma machine reset to its original state: Ready to start from scratch!\n");
}

// -----------------------------------------------------------------------------------------------
// crankThatCipher - Crank that cipher wheel! This function rotates the rotors of the Enigma machine
// to create a new mapping for the encryption and decryption process. This was truly unique to the
// Enigma machine and was one of the reasons why it was so secure. The dynamic rotor mechanism ensured
// after every keypress, that a new mapping was used to encrypt or decrypt the message. Of course,
// sender and receiver had to be in sync with their rotor settings.
// -----------------------------------------------------------------------------------------------
// @param iteration as an integer to track the number of keypresses.
// -----------------------------------------------------------------------------------------------
void crankThatCipher(int iteration) {
    rotate(&smallRotor);

    if (iteration % rotorLength == 0 && iteration != 0) {
        rotate(&mediumRotor);
    }

    // Large rotor rotates after every full rotation of the medium rotor
    if (iteration % (rotorLength * rotorLength) == 0 && iteration != 0) {
        rotate(&largeRotor);
    }
}

// -----------------------------------------------------------------------------------------------
// encrypt - Encrypt a single character using the Enigma machine. This function takes a single
// character as input and encrypts it using the rotor mappings of the small, medium, and large rotor.
// The character is passed through the rotor mappings in a specific order to create the encrypted
// character. The Enigma machine was a marvel of engineering and cryptography, and this function
// emulates its encryption process.
// -----------------------------------------------------------------------------------------------
// @param inputChar as a character to be encrypted.
// @param smallRotor as a pointer to the small rotor.
// @param mediumRotor as a pointer to the medium rotor.
// @param largeRotor as a pointer to the large rotor.
// @return the encrypted character.
// -----------------------------------------------------------------------------------------------
char encrypt(char inputChar, Rotor *smallRotor, Rotor *mediumRotor, Rotor *largeRotor) {
        
    // Step 1: checking if the input character is a encryptable character
    if (strchr(smallRotor->original, inputChar) == NULL) {
        // Character not found in mapping, return as-is
        return inputChar;
    }
 
    // Step 2: Find inputChar in smallRotor.mapping and get the index
    int index = -1;
    for (int i = 0; i < rotorLength; i++) {
        if (smallRotor->mapping[i] == inputChar) {
            index = i;
            break;
        }
    }
    // Now it shouldn't be necessary to check if index is -1, because we already checked
    // if the character is encryptable but we will keep it for safety.
    if (index == -1) {
        printf("Error: Character '%c' not found in smallRotor.\n", inputChar);
        return '?';  // Return a placeholder if the character is invalid
    }

    // Step 3: Map inputChar to mediumRotor.mapping[index]
    char currentChar = mediumRotor->mapping[index];

    // Step 4: Find the index of currentChar in largeRotor.mapping
    index = -1;
    for (int i = 0; i < rotorLength; i++) {
        if (largeRotor->mapping[i] == currentChar) {
            index = i;
            break;
        }
    }

    // Step 5: Map back to smallRotor.mapping[index]
    return smallRotor->mapping[index];
}

// -----------------------------------------------------------------------------------------------
// decrypt - Decrypt a single character using the Enigma machine. This function takes a single
// character as input and decrypts it using the rotor mappings of the small, medium, and large rotor.
// The character is passed through the rotor mappings in reverse order to create the decrypted
// character. The Enigma machine was a marvel of engineering and cryptography, and this function
// emulates its decryption process.
// -----------------------------------------------------------------------------------------------
// @param inputChar as a character to be decrypted.
// @param smallRotor as a pointer to the small rotor.
// @param mediumRotor as a pointer to the medium rotor.
// @param largeRotor as a pointer to the large rotor.
// @return the decrypted character.
// -----------------------------------------------------------------------------------------------
char decrypt(char inputChar, Rotor *smallRotor, Rotor *mediumRotor, Rotor *largeRotor) {

    // Step 1: checking if the input character is a encryptable character
    if (strchr(smallRotor->original, inputChar) == NULL) {
        // Character not found in mapping, return as-is
        return inputChar;
    }

    // Step 2: Find inputChar in smallRotor.mapping
    int index = -1;
    for (int i = 0; i < rotorLength; i++) {
        if (smallRotor->mapping[i] == inputChar) {
            index = i;  // Find index of inputChar in smallRotor
            break;
        }
    }
    // Now it shouldn't be necessary to check if index is -1, because we already checked
    // if the character is encryptable but we will keep it for safety.
    if (index == -1) {
        printf("Error: Character '%c' not found in smallRotor.\n", inputChar);
        return '?'; // Return placeholder for invalid characters
    }

    // Step 3: Get character at index from largeRotor.mapping
    char currentChar = largeRotor->mapping[index];

    // Step 4: Find index of currentChar in mediumRotor.mapping
    index = -1;
    for (int i = 0; i < rotorLength; i++) {
        if (mediumRotor->mapping[i] == currentChar) {
            index = i;  // Find index of character in mediumRotor
            break;
        }
    }

    // Step 5: Retrieve original character at index from smallRotor.mapping
    return smallRotor->mapping[index];
}

// -----------------------------------------------------------------------------------------------
// rotate - Rotate a rotor by one position. This function rotates the rotor mapping by one position,
// simulating the rotor movement in the Enigma machine. The rotor mapping is circular, and after
// reaching the last position, it wraps around to the first position. This function is used to
// rotate the rotors of the Enigma machine during the encryption and decryption process.
// -----------------------------------------------------------------------------------------------
// @param rotor as a pointer to the rotor to be rotated.
// -----------------------------------------------------------------------------------------------
void rotate(Rotor *rotor) {
    if (!rotor->initialized) {
        printf("Error: Attempted to rotate an uninitialized rotor.\n");
        return;
    }

    char firstChar = rotor->mapping[0];
    for (int i = 0; i < rotorLength - 1; i++) {
        rotor->mapping[i] = rotor->mapping[i + 1];
    }
    rotor->mapping[rotorLength - 1] = firstChar;

    // Debug print for the rotated rotor
    // printf("Rotated %sRotor: %s\n", rotor->name, rotor->mapping);
}

// Clean up memory for all rotors
void cleanMemoryLane() {
    freeRotorMemory(&smallRotor);
    freeRotorMemory(&mediumRotor);
    freeRotorMemory(&largeRotor);
    
    //printf("Memory lane has been cleaned up. Safe travels!\n");
}