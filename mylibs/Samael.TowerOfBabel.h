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
 * Tue 2025-03-25 File created.                                                 Version: 00.01
 * -------------------------------------------------------------------------------------------
 * To Do's:
 * ********************************************************************************************/
#ifndef SAMAEL_TOWEROFBABEL_H
#define SAMAEL_TOWEROFBABEL_H

#ifdef _WIN32
    // -------------------------------------------------------------------------------------------
    // Include Samael.TowerOfBabel headers for the library's functionality under Unix systems.
    // -------------------------------------------------------------------------------------------
    #include "TowerOfBabel\Enigma.h"
    #include "TowerOfBabel\Rotor.h"

#else
    // -------------------------------------------------------------------------------------------
    // Include Samael.TowerOfBabel headers for the library's functionality under Windows.
    // -------------------------------------------------------------------------------------------
    #include "TowerOfBabel/Enigma.h"
    #include "TowerOfBabel/Rotor.h"

#endif

#endif