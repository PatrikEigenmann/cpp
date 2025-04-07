/* *******************************************************************************************
 * Samael.TowerOfBabel.h - Samael.TowerOfBabel is a cryptographic package designed to secure
 * textual communication over public networks. It provides encryption, encoding, and decoding
 * mechanisms ranging from nostalgic Enigma-style ciphers to modern AES, SHA, and advanced
 * hashing techniques. By integrating this package, developers can protect sensitive data and
 * ensure confidentiality in their applications. Import Samael.TowerOfBabel to incorporate
 * reliable and scalable encryption solutions into your system.
 * 
 * Compiler instructions:
 * 1) gcc -shared -o bin/libSamaelTowerOfBabel.so Samael.TowerOfBabel.c TowerOfBabel/Enigma.c
 *                  TowerOfBabel/Rotor.c
 * or pmake Samael.TowerOfBabel.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Change Log:
 * Tue 2025-03-25 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Added component Enigma to Samael.TowerOfBabel.                Version: 00.02
 * Sun 2025-04-06 Added component Rotor to Samael.TowerOfBabel.                 Version: 00.03
 * Sun 2025-04-06 Register Samael.TowerOfBabel with Version Control.            Version: 00.04
 * ********************************************************************************************/
#include "Samael.h"
#include "Samael.TowerOfBabel.h"

// -------------------------------------------------------------------------------------------
// regCProgress - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// Samael.ToolBox.cProgress.c, which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void regTowerOfBabel(void) {
    // Register the component with the version control system
    registerVersion("Samael.TowerOfBabel", "", 0, 4);
}