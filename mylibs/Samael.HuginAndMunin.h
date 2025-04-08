/* *******************************************************************************************
 * Samael.HuginAndMunin.h - Samael.HuginAndMunin is the essential module for managing logging
 * and messaging within the Samael framework. Named after Odin's legendary ravens, it symbolizes
 * the flow of thought and memory, embodying the transmission and preservation of vital
 * information. This module handles both real-time communication and long-term logging with
 * precision and reliability. Samael.HuginAndMunin ensures that every message is delivered
 * accurately and every log entry is stored for reference and analysis. Its versatile design
 * supports integration with other modules and external systems, making it adaptable for a wide
 * range of use cases. From debugging to data pipelines, this module provides the infrastructure
 * needed for seamless information flow. Samael.HuginAndMunin bridges the past and present,
 * capturing the narrative of events and enabling insightful decision-making.
 * 
 * Compile instructions:
 * gcc -shared Samael.HuginAndMunin.c -o bin/libSamael.HuginAndMunin.so
 * or pmake Samael.HuginAndMunin.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-03-26 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Register package HuginAndMunin with it's version number.      Version: 00.02
 * Mon 2025-04-07 Implemented the new Samael naming convention.                 Version: 00.03
 * Tue 2025-04-08 BugFix: RegisterVersion("HuginAndMunin", "", 0, 4);           version: 00.04
 * ********************************************************************************************/

#ifndef SAMAEL_HUGINANDMUNIN_H
#define SAMAEL_HUGINANDMUNIN_H

#ifdef _WIN32
    // -------------------------------------------------------------------------------------------
    // Include Samael.HuginAndMunin headers for the library's functionality under Windows.
    // -------------------------------------------------------------------------------------------

#else
    // -------------------------------------------------------------------------------------------
    // Include Samael.HuginAndMunin headers for the library's functionality under Unix systems.
    // -------------------------------------------------------------------------------------------

#endif

// -------------------------------------------------------------------------------------------
// regHuginAndMunin - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.HuginAndMunin.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
void RegHuginAndMunin(void);

#endif