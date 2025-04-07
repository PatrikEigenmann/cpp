/* *******************************************************************************************
 * Framework.c - <description>
 *
 * Compile instructions:
 * gcc/clang Framework.c -o Framework
 * pmake Framework.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Sun 2025-04-06 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Package name corrected.                                       Version: 00.02
 * -------------------------------------------------------------------------------------------
 * To Do's:
 * ********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Framework.h"

#ifdef _WIN32
// --= Windows Section please uncomment what you need! =-- //
#include "Chronicle/Version.h"

#else
// --= MacOS/Linux Section please uncomment what you need! =-- //
#include "Chronicle/Version.h"

#endif

// -------------------------------------------------------------------------------------------
// The snakeHead is a word game for the head of a linked list. Because the archangel Samael is
// often depicted as a snake, the head of the list is called snakeHead. This is a playful
// reference to the name Samael and the structure of the linked list. In this linked list, all
// software components are registered, and the first element is pointed to by the snakeHead.
// --------------------------------------------------------------------------------------------
static Version* snakeHead = NULL;

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
__attribute__((constructor)) void regFramework(void) {
    // For example, registering the framework itself with version 1.0.
    registerVersion("Samael", "Framework", 0, 2);
}

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
void registerVersion(const char* package, const char* name, int major, int minor) {
    Version* newVersion = createVersion((char*)package, (char*)name, major, minor);
    if (newVersion == NULL) {
        return;  // Alternatively, you could handle the error appropriately
    }
    if (snakeHead == NULL) {
        snakeHead = newVersion;
    } else {
        // Append at the end of the linked list
        Version* current = snakeHead;
        while (current->tail != NULL) {
            current = current->tail;
        }
        current->tail = newVersion;
    }
}

// -------------------------------------------------------------------------------------------
// This function retrieves the first version entry in the snake (linked list). It returns a pointer
// to the head of the linked list containing all registered version entries. This allows other
// parts of the program to access and manipulate the version information as needed.
//
// @return Version* - Pointer to the head of the linked list containing all registered versions.
// -------------------------------------------------------------------------------------------
const Version* getVersionList(void) {
    return snakeHead;
}

// -------------------------------------------------------------------------------------------
// This function creates a formatted string representing the version information
// for the whole software project. It formats the string to a human-readable format
// and stores it in the provided buffer.
//
// @param buffer    - The buffer to store the formatted string.
// @param bufferSize - The size of the buffer.
// -------------------------------------------------------------------------------------------
void toListString(char* buffer, size_t bufferSize) {
    if (buffer == NULL || bufferSize == 0) {
        return;
    }
    // Ensure the buffer starts as an empty string.
    buffer[0] = '\0';
    
    Version* current = snakeHead;
    char lineBuffer[256];  // Temporary buffer for each version's formatted string.
    
    while (current != NULL) {
        toString(current, lineBuffer);
        strncat(buffer, lineBuffer, bufferSize - strlen(buffer) - 1);
        strncat(buffer, "\n", bufferSize - strlen(buffer) - 1);
        current = current->tail;
    }
}

// -------------------------------------------------------------------------------------------
// This function prints the version information of all registered components.
// It iterates through the linked list of version entries and prints the package name,
// component name, major version number, and minor version number for each entry.
// --------------------------------------------------------------------------------------------
void printListString(void) {
    char buffer[1024];  // Adjust size as needed for your expected version list output.
    toListString(buffer, sizeof(buffer));
    printf("%s", buffer);
}