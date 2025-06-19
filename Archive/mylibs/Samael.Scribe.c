/* *******************************************************************************************
 * Samael.Scribe.c - Samael.Scribe is the dedicated module for handling file operations
 * within the Samael framework. Its purpose is to streamline tasks such as reading, writing, and
 * managing files with efficiency and precision. Samael.Scribe provides a robust toolkit for
 * working with various file types and structures, ensuring compatibility across diverse use
 * cases. The module is designed to simplify complex file operations, offering intuitive methods
 * for seamless integration into larger workflows. It also emphasizes data integrity, ensuring
 * that files are handled safely and reliably. Whether creating, organizing, or modifying files,
 * Samael.Scribe serves as a reliable assistant in managing the written artifacts of any
 * application. Its versatility and reliability make it an indispensable element of the
 * framework.
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-03-26 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Register package Scribe with it's version number.             Version: 00.02
 * Mon 2025-04-07 Implemented the Samael naming convention.                     Version: 00.03
 * Tue 2025-04-08 BugFix: RegisterVersion("Samael.Scribe", "", 0, 4);           Version: 00.04
 * ********************************************************************************************/

#include "Samael.h"
#include "Samael.Scribe.h"

// -------------------------------------------------------------------------------------------
// RegScribe - Automatically registers this component's version information with the versioning
// system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.Entanglement.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void RegScribe(void) {
    // Register the Scribe package with its version number.
    RegisterVersion("Samael.Scribe", "", 0, 4);
}