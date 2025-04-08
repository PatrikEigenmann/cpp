/* *******************************************************************************************
 * Version.c - This file is part of the Samael framework, which serves as a comprehensive
 * development environment for building and managing software applications. The framework
 * emphasizes clarity, transparency, and functionality, allowing developers to focus on
 * execution without obstacles.
 * 
 * The Version.c file is specifically designed to handle version management within the
 * Samael framework and other software projects. It provides a structured approach to track
 * and manage different versions of components and packages. The Version structure includes
 * fields for the package name, component name, major and minor version numbers, and a pointer
 * to the next version entry in a linked list. This allows for dynamic management of
 * registered components and facilitates the organization of version information.
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Sun 2025-04-06 File created.                                                 Version: 00.01
 * Mon 2025-04-07 Changed All names to new Samael naming convention.            Version: 00.02
 * Tue 2025-04-08 Bug Fixed: Call of ToString(versionIn, buffer); L116          Version: 00.03
 * ********************************************************************************************/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    // --= Windows Section please uncomment what you need! =-- //
    #include "..\Framework.h"

#else
    // --= MacOS/Linux Section please uncomment what you need! =-- //
    #include "../Framework.h"

#endif

#include "Version.h"

// -------------------------------------------------------------------------------------------
// RegVersion - Automatically registers this component's version information with the 
// versioning system of the Samael framework.
// 
// This function is marked with the constructor attribute in the implementation file 
// (Version.c), which means it will automatically be executed prior to the execution 
// of the main() function. This pre-main invocation is part of the automatic versioning 
// mechanism, ensuring that the version details for this component are registered as soon 
// as the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void RegVersion(void) {
    RegisterVersion("Samael.Chronicle", "Version", 0, 2);
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
Version* CreateVersion(char* packageIn, char* nameIn, int majorIn, int minorIn) {
    
    Version* versionOut = (Version*)malloc(sizeof(Version));
    
    if (versionOut == NULL) {
        fprintf(stderr, "Memory allocation failed for new version entry.\n");
        return NULL;
    }
    
    snprintf(versionOut->package, sizeof(versionOut->package), "%s", packageIn);
    snprintf(versionOut->name, sizeof(versionOut->name), "%s", nameIn);
    versionOut->major = majorIn;
    versionOut->minor = minorIn;
    versionOut->tail = NULL;  // Initialize the tail pointer to NULL
    
    return versionOut;
}

// -------------------------------------------------------------------------------------------
// This function creates a formatted string representing the version information 
// for the given Version entry. If the Version's name is empty, the entry is treated 
// as a package-only entry. Otherwise, it's treated as a component entry.
// 
// @param versionIn - The Version object.
// @param bufferIn  - The memory to write the formatted string into.
// -------------------------------------------------------------------------------------------
void ToString(Version* versionIn, char* bufferIn) {
    
    if (versionIn == NULL || bufferIn == NULL) {
        fprintf(stderr, "Invalid version or buffer pointer.\n");
        return;
    }

    // Check if the name field is empty, meaning it is a package-only entry.
    int packageOnly = (versionIn->name[0] == '\0');

    if (packageOnly) {
        // For package-only entries, display the package with version and a horizontal line.
        snprintf(bufferIn, 256, "\nPackage:   %s v%02d.%02d\n------------------------------", 
            versionIn->package, versionIn->major, versionIn->minor);
    } else {
        // For component entries, display the package and component name along with the version.
        snprintf(bufferIn, 256, "Component: %s.%s v%02d.%02d", 
            versionIn->package, versionIn->name, versionIn->major, versionIn->minor);
    }
}

// -------------------------------------------------------------------------------------------
// This function prints the version information for the given Version entry to the standard
// output by first converting the version entry to a formatted string with toString().
// 
// @param versionIn - The Version entry to be printed.
// -------------------------------------------------------------------------------------------
void PrintVersion(Version* versionIn) {
    if (versionIn == NULL) {
        fprintf(stderr, "Invalid version pointer.\n");
        return;
    }
    char buffer[256];
    ToString(versionIn, buffer);
    printf("%s\n", buffer);
}