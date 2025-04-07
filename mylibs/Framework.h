/* *******************************************************************************************
 * Framework.h - <description>
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Sun 2025-04-06 File created.                                                 Version: 00.01
 * ********************************************************************************************/

#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <stdlib.h>

#ifdef _WIN32
// --= Windows Section! =-- //
#include "Chronicle/Version.h"

#else
// --= MacOS/Linux Section! =-- //
#include "Chronicle/Version.h"

#endif

// -------------------------------------------------------------------------------------------
// regFramework - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Framework.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
void regFramework(void);

// -------------------------------------------------------------------------------------------
// This function creates a new version entry with the specified package name, component name,
// major version number, and minor version number. It initializes the version entry and
// returns a pointer to the newly created Version structure.
//
// @param package  - The name of the framework or software package.
// @param name     - The name of the component or module.
// @param major    - The major version number.
// @param minor    - The minor version number.
// -------------------------------------------------------------------------------------------
void registerVersion(const char* package, const char* name, int major, int minor);

// -------------------------------------------------------------------------------------------
// This function retrieves the version information of the specified component.
// It searches through the linked list of version entries and returns a pointer to the
// Version structure that matches the given package and component names.
//
// @param buffer   - The buffer to store the version string.
// @param bufferSize - The size of the buffer.
// -------------------------------------------------------------------------------------------
void toListString(char* buffer, size_t bufferSize);

// -------------------------------------------------------------------------------------------
// This function prints the version information of all registered components.
// It iterates through the linked list of version entries and prints the package name,
// component name, major version number, and minor version number for each entry.
// -------------------------------------------------------------------------------------------
void printListString(void);

// -------------------------------------------------------------------------------------------
// getVersionList - This function retrieves the list of registered versions.
// It returns a pointer to the head of the linked list containing all registered
// version entries. This allows other parts of the program to access and manipulate
// the version information as needed.
// -------------------------------------------------------------------------------------------
const Version* getVersionList(void);

#endif