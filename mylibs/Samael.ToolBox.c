/* *******************************************************************************************
 * Samael.ToolBox.c - Samael.ToolBox is the foundational module for practical and
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
 * gcc -shared -o bin/libSamael.ToolBox.so Samael.ToolBox.c ToolBox/cManPage.c ToolBox/cProgress.c
 *                   ToolBox/cVersion.c
 * or pmake Samael.ToolBox.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp 
 * -------------------------------------------------------------------------------------------
 * Sat 2025-03-22 File created.                                                 Version: 00.01
 * Wed 2025-03-26 Folder update: From Utility to ToolBox.                       Version: 00.02
 * Sun 2025-04-06 Depricate cVersion.h and moved it to Samael.Chronicle.        Version: 00.03
 * Sun 2025-04-06 Register package ToolBox with it's version number.            Version: 00.04
 * ********************************************************************************************/
#include "Samael.h"
#include "Samael.ToolBox.h"

// -------------------------------------------------------------------------------------------
// regToolBox - Automatically registers this component's version information with the versioning
// system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// Samael.ToolBox.c, which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void regToolBox(void) {
    // Register the ToolBox package with its version number.
    registerVersion("Samael.ToolBox", "", 0, 4);
}
