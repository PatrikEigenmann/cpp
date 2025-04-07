/* *******************************************************************************************
 * Samael.Necronomicon.h - Samael.Necronomicon stands as the ultimate repository for
 * powerful and arcane knowledge in the realm of databases. This module seamlessly handles
 * connectivity, storage, and analytics for systems like SQLite, MySQL, and Progress, offering
 * both flexibility and reliability. Samael.Necronomicon is designed to simplify complex database
 * interactions, making it effortless to query, manage, and analyze data. With its intuitive
 * interface, it empowers developers to uncover insights and optimize workflows. From handling
 * vast datasets to ensuring secure connections, this module provides a robust foundation for
 * all database-related tasks. Samael.Necronomicon bridges the gap between raw data and meaningful
 * results, embodying the mystical transformation of information into wisdom. By harnessing its
 * capabilities, users can command their databases with confidence and precision.
 * 
 * Compile instructions:
 * gcc -shared Samael.Necronomicon.c -o bin/libSamael.Necronomicon.so
 * or pmake Samael.Necronomicon.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-03-26 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Register package Necronomicon with it's version number.       Version: 00.02
 * ********************************************************************************************/

#ifndef SAMAEL_NECRONOMICON_H
#define SAMAEL_NECRONOMICON_H

#ifdef _WIN32
    // -------------------------------------------------------------------------------------------
    // Include Samael.Necronomicon headers for the library's functionality under Windows.
    // -------------------------------------------------------------------------------------------

#else
    // -------------------------------------------------------------------------------------------
    // Include Samael.Necronomicon headers for the library's functionality under Unix systems.
    // -------------------------------------------------------------------------------------------

#endif

// -------------------------------------------------------------------------------------------
// regNecronomicon - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.Necronomicon.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
void regNecronomicon(void);

#endif