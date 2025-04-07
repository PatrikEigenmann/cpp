/* ***********************************************************************************************
 * Enigma.h - This c header file corresponds with the Enigma.c and is an attempt to emulate the
 * Enigma cipher machine used in World War II. The Enigma cipher machine was originally developed
 * and widely used in the early to mid-20th century to protect commercial, diplomatic, and military
 * communication. Nazi Germany extensively employed it during World War II, across all branches of
 * their military. The machine was considered so secure that it was used to encipher even the most
 * top-secret messages.
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
 * Thu 2025-03-27 Defined ROTOR_LENTGH here, because it is enigma specific.         Version: 00.02
 * Thu 2025-03-27 setRotorLength in powerUp before initializing the rotors.         Version: 00.03
 * Sun 2025-04-06 Register component with its version in the Samael Framework.      Version: 00.04
 * Sun 2025-04-06 Renamed encrypt and decrypt to encryptChar and decryptChar.       Version: 00.05
 * ***********************************************************************************************/
#ifndef ENIGMA_H
#define ENIGMA_H

#include "Rotor.h"

// -------------------------------------------------------------------------------------------
// regEnigma - Automatically registers this component's version information with the versioning
// system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.TowerOfBabel.Enigma.c), which means it will automatically be executed prior to the
// execution of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
void regEnigma(void);

// -----------------------------------------------------------------------------------------------
// These types are specifically used for the enigma cipher machine to identify the rotor type and
// its mapping. A mapping is the sequence of values the rotor is using to work its magic. The enigma
// cipher machine used three rotors with different mappings to encrypt and decrypt messages. The
// small, medium, and the large rotor. Almost reminds me of the good, the bad, and the ugly. :)
// -----------------------------------------------------------------------------------------------
#define SMALL 0     // Small rotor type
#define MEDIUM 1    // Medium rotor type
#define LARGE 2     // Large rotor type

// -----------------------------------------------------------------------------------------------
// Define the rotor's length to ensure consistency across the program.
// -----------------------------------------------------------------------------------------------
#define ROTOR_LENGTH 95

// -----------------------------------------------------------------------------------------------
// Definition of the three rotors used in the Enigma machine. The small, medium, and large rotor
// are the core components of the Enigma machine. Each rotor has a specific mapping that is used
// to encrypt and decrypt messages. The rotor struct is defined in Rotor.h.
// -----------------------------------------------------------------------------------------------
extern Rotor smallRotor, mediumRotor, largeRotor;

// -----------------------------------------------------------------------------------------------
// powerUp - This is truly a magical moment. I bet when german engineers first time powered up the
// Enigma machine, their eyes were sparkling like little kids on Christmas. I hope you can capture
// the same magical moment when you include my Enigma.h and plug the beast in. Power it up baby.
// There is something seriously satisfying just writing the word "powerUp". Ignite your cipher machine
// and let the magic begin.
// -----------------------------------------------------------------------------------------------
void powerUp();

// -----------------------------------------------------------------------------------------------
// startFromScratch - Reset the Enigma machine to its original state. This function is used to
// reset the rotor mappings to their original state. It is used to start the Enigma machine from
// scratch, ensuring that the rotor mappings are in their initial configuration.
// -----------------------------------------------------------------------------------------------
void startFromScratch();

// -----------------------------------------------------------------------------------------------
// crankThatCipher - Crank that cipher wheel! This function rotates the rotors of the Enigma machine
// to create a new mapping for the encryption and decryption process. This was truly unique to the
// Enigma machine and was one of the reasons why it was so secure. The dynamic rotor mechanism ensured
// after every keypress, that a new mapping was used to encrypt or decrypt the message. Of course,
// sender and receiver had to be in sync with their rotor settings.
// -----------------------------------------------------------------------------------------------
// @param iteration as an integer to track the number of keypresses.
// -----------------------------------------------------------------------------------------------
void crankThatCipher(int iteration);

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
char encryptChar(char inputChar, Rotor *smallRotor, Rotor *mediumRotor, Rotor *largeRotor);

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
char decryptChar(char inputChar, Rotor *smallRotor, Rotor *mediumRotor, Rotor *largeRotor);

// -----------------------------------------------------------------------------------------------
// rotate - Rotate a rotor by one position. This function rotates the rotor mapping by one position,
// simulating the rotor movement in the Enigma machine. The rotor mapping is circular, and after
// reaching the last position, it wraps around to the first position. This function is used to
// rotate the rotors of the Enigma machine during the encryption and decryption process.
// -----------------------------------------------------------------------------------------------
// @param rotor as a pointer to the rotor to be rotated.
// -----------------------------------------------------------------------------------------------
void rotate(Rotor *rotor);

// -----------------------------------------------------------------------------------------------
// cleanMemoryLane - Clean up memory for all rotors. This function is used to free the memory
// allocated for the rotor mappings. It ensures that no memory leaks occur during the execution
// of the program. Memory management is crucial in C programming, and this function helps to
// clean up the memory used by the rotor mappings.
// -----------------------------------------------------------------------------------------------
void cleanMemoryLane();

#endif