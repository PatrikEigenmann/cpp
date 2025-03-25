/* ***********************************************************************************************
 * _enigma.c - This C console application is a very simplified emulation of the Enigma cipher
 * machine used in World War II. The Enigma cipher machine was originally developed and widely
 * used in the early to mid-20th century to protect commercial, diplomatic, and military
 * communication. Nazi Germany extensively employed it during World War II, across all branches
 * of their military. The machine was considered so secure that it was used to encipher even the
 * most top-secret messages.
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
 * Despite its complexity and high level of security, the Enigma machine was not
 * unbreakable. Polish mathematician Marian Rejewski and his team were the first to break
 * the code in the early 1930s. During World War II, the British established the secret
 * code-breaking unit known as Ultra, led by mathematician Alan M. Turing. Intelligence
 * gleaned from decrypting Enigma-encoded messages significantly contributed to the Allied
 * victories.
 *
 * This program is a showcase of the capabilities of the Enigma machine. It demonstrates
 * how messages can be encrypted and decrypted using the principles of rotor-based
 * cryptography, offering a simplified example of its ingenious design.
 *
 * Compile instructions:
 * gcc _enigma.c -o enigma -L../mylibs/bin -lSamael
 * pmake enigma.makefile
 * -----------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -----------------------------------------------------------------------------------------------
 * Version Control:
 * Tue 2025-03-25 File created.                                                     Version: 00.01
 * ***********************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // For bool data type

#include "../mylibs/Samael.h"

int main() {

    // Power up the Enigma machine
    powerUp();

    // Input message
    char message[] = "Beautiful work, Patrik! The encryption seamlessly transforms the message.\0";
    char encryptedMessage[sizeof(message)];
    char decryptedMessage[sizeof(message)];

    // Encrypt message
    for (int i = 0; message[i] != '\0'; i++) {
        // Encrypt each character
        encryptedMessage[i] = encrypt(message[i], &smallRotor, &mediumRotor, &largeRotor);
        // Rotate rotors apropietly
        crankThatCipher(i);
    }

    // Null-terminate encrypted message
    encryptedMessage[sizeof(message)-1] = '\0';

    // Reset rotors
    startFromScratch();

    for(int i = 0; encryptedMessage[i] != '\0'; i++) {
        decryptedMessage[i] = decrypt(encryptedMessage[i], &smallRotor, &mediumRotor, &largeRotor);
        crankThatCipher(i);
    }

    decryptedMessage[sizeof(message)-1] = '\0';

    // Print results
    printf("Original Message : %s\n", message);
    printf("Encrypted Message: %s\n", encryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);


    // Free memory for rotors
    cleanMemoryLane();

    return 0;
}