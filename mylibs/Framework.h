/* *******************************************************************************************
 * Framework.h - The Framework component is responsible to register each package and comoponent
 * with the versioning system of the Samael framework. It provides the necessary functionality
 * to do so. in the Samael framework, each component has a two digit major and minor number.
 * The major number is increased for major software releases, while the minor number is increased
 * after changes, bug fixes, or other minor updates.
 * 
 * The key differences between the Samael versioning system and traditional software versioning
 * systems are:
 * 1. The Samael versioning system is fully integrated into the runtime binaries of the software.
 * 2. The versioning system is half-automated during runtime, meaning the information is available
 *    during the runtime of the application.
 * 3. The versioning system uses automation mechanisms during build process, making version maintenance
 *    of each component easier and more efficient.
 * 4. The versioning system is designed to be used in a distributed environment, where multiple
 *    components may be running on different machines or devices.
 * 
 * The Framework component is a key part of the Samael framework, providing the necessary
 * functionality for the Samael components and their lifecycles.
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Sun 2025-04-06 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Package name corrected.                                       Version: 00.02
 * Mon 2025-04-07 Bugfix: Dynamically allocated string in toListString().       Version: 00.03
 * Mon 2025-04-07 Bugfix: Displaying package and component in toListString().   Version: 00.04
 * Mon 2025-04-07 Implemented all new Samael nameing conventions.               Version: 00.05
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
// RegFramework - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Framework.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
void RegFramework(void);

// -------------------------------------------------------------------------------------------
// This function creates a new version entry with the specified package name, component name,
// major version number, and minor version number. It initializes the version entry and
// returns a pointer to the newly created Version structure.
//
// @param packageIn - The name of the framework or software package.
// @param nameIn    - The name of the component or module.
// @param majorIn   - The major version number.
// @param minorIn   - The minor version number.
// -------------------------------------------------------------------------------------------
void RegisterVersion(const char* packageIn, const char* nameIn, int majorIn, int minorIn);

// -------------------------------------------------------------------------------------------
// Generates a formatted string containing version information for the entire software project.
// The function dynamically allocates memory for the output, ensuring sufficient space to store 
// all registered components and packages in a structured, human-readable format.
//
// The returned string is dynamically allocated and must be freed by the caller when no longer needed.
//
// @return A dynamically allocated string containing the version information. The caller is 
//         responsible for freeing this memory.
// -------------------------------------------------------------------------------------------
char* ToListString(void);

// -------------------------------------------------------------------------------------------
// This function prints the version information of all registered components.
// It iterates through the linked list of version entries and prints the package name,
// component name, major version number, and minor version number for each entry.
// -------------------------------------------------------------------------------------------
void PrintListString(void);

// -------------------------------------------------------------------------------------------
// GetVersionList - This function retrieves the list of registered versions.
// It returns a pointer to the head of the linked list containing all registered
// version entries. This allows other parts of the program to access and manipulate
// the version information as needed.
// -------------------------------------------------------------------------------------------
const Version* GetVersionList(void);

#endif