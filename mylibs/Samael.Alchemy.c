/* *******************************************************************************************
 * Samael.Alchemy.c - Samael.Alchemy is designed to transform the fundamental
 * elements of mathematics into powerful tools for solving complex problems. It provides a rich
 * suite of operations, from basic calculations to advanced equation solving and symbolic
 * manipulation. This module is built to handle numerical data with precision and supports
 * seamless integration into larger workflows. With its intuitive interface, Samael.Alchemy
 * aims to simplify mathematical processes while maintaining flexibility for intricate
 * computations. It empowers developers and users to derive insights, optimize algorithms,
 * and explore mathematical patterns effectively. Whether applied to scientific research,
 * engineering tasks, or financial analysis, Samael.Alchemy is the cornerstone for mathematical
 * mastery within the Samael framework. Its ability to make abstract mathematical concepts
 * actionable and accessible ensures it remains an indispensable resource.
 *
 * Compile instructions:
 * gcc -shared Samael.Alchemy.c -o bin/libSamael.Alchemy.so
 * or pmake Samael.Alchemy.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-03-26 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Register package Alchemy with it's version number.            Version: 00.02
 * ********************************************************************************************/

#include "Samael.h"
#include "Samael.Alchemy.h"

// -------------------------------------------------------------------------------------------
// regAlchemy - Automatically registers this component's version information with the versioning
// system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.Alchemy.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void regAlchemy(void) {
    // Register the version information for the Samael.Alchemy component
    registerVersion("Samael.Alchemy", "", 0, 1);
}