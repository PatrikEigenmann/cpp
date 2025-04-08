/* *******************************************************************************************
 * Samael.Tabernacle.h - Samael.Tabernacle is the gateway between the graphical world and the
 * unseen binary realm. It transforms user interactions—clicks, gestures, and input—into
 * structured operations, seamlessly linking the visual interface with the underlying computational
 * logic.
 * 
 * Like a tabernacle connecting reality to deeper, invisible forces, Samael.Tabernacle is where
 * human intention meets machine execution. It ensures that every action taken within the interface
 * translates into precise, optimized processes at the system level. Whether handling complex
 * workflows, dynamic user responses, or data visualization, this module makes sure the UI and the
 * binary engine work in perfect harmony.
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-03-26 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Register package Tabernacle with it's version number.         Version: 00.02
 * Mon 2025-04-07 Implemented the Samael naming convention.                     Version: 00.03
 * Tue 2025-04-08 BugFix: RegisterVersion("Samael.Tabernacle", "", 0, 4);       Version: 00.04
 * ********************************************************************************************/

#ifndef SAMAEL_TABERNACLE_H
#define SAMAEL_TABERNACLE_H

#ifdef _WIN32
    // -------------------------------------------------------------------------------------------
    // Include Samael.Tabernacle headers for the library's functionality under Windows.
    // -------------------------------------------------------------------------------------------

#else
    // -------------------------------------------------------------------------------------------
    // Include Samael.Tabernacle headers for the library's functionality under Unix systems.
    // -------------------------------------------------------------------------------------------

#endif

// -------------------------------------------------------------------------------------------
// RegTabernacle - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.Tabernacle.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
void RegTabernacle(void);

#endif