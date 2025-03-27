/* *******************************************************************************************
 * Samael.TowerOfBabel.h - Samael.ToolBox is the foundational module for practical and
 * essential utilities within the Samael framework. It serves as a centralized repository for
 * frequently used tools, offering streamlined methods to perform common tasks such as type
 * checks, validations, and basic operations. This module is intentionally general-purpose,
 * providing accessible and efficient solutions for handling routine programming needs.
 * Samael.ToolBox ensures that developers can rely on a consistent set of functions to simplify
 * their workflows without duplicating efforts across different modules. Its lightweight design
 * prioritizes adaptability, making it easy to integrate into a wide range of applications.
 * From basic operations to sophisticated utilities, Samael.ToolBox embodies versatility and
 * efficiency, supporting both the framework and its extensions. It stands as a reliable
 * companion for developers seeking clarity and simplicity in their codebase.
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