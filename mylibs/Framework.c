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
// RegFramework - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Framework.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void RegFramework(void) {
    // For example, registering the framework itself with version 1.0.
    RegisterVersion("Samael", "Framework", 0, 5);
}

// -------------------------------------------------------------------------------------------
// This function creates a new version entry with the specified package name, component name,
// major version number, and minor version number. It initializes the version entry and
// returns a pointer to the newly created Version structure.
//
// @param packageIn  - The name of the framework or software package.
// @param nameIn     - The name of the component or module.
// @param majorIn    - The major version number.
// @param minorIn    - The minor version number.
// -------------------------------------------------------------------------------------------
void RegisterVersion(const char* packageIn, const char* nameIn, int majorIn, int minorIn) {
    
    Version* newVersion = CreateVersion((char*)packageIn, (char*)nameIn, majorIn, minorIn);
    
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
const Version* GetVersionList(void) {
    return snakeHead;
}

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
char* ToListString(void) {
    
    if (snakeHead == NULL) {
        return strdup("");  // Return an empty string if no versions are registered
    }

    Version* current = snakeHead;
    size_t totalSize = 1; // Start with space for the null terminator

    // First pass: Calculate required buffer size dynamically
    while (current != NULL) {
        if (strcmp(current->name, "") == 0) { 
            // It's a package
            totalSize += snprintf(NULL, 0, "\nPackage:   %s v%02d.%02d\n------------------------------\n",
                                  current->package, current->major, current->minor);
        } else { 
            // It's a component
            totalSize += snprintf(NULL, 0, "Component: %s.%s v%02d.%02d\n",
                                  current->package, current->name, current->major, current->minor);
        }
        current = current->tail;
    }

    // Allocate the final buffer
    char *bufferOut = malloc(totalSize);
    if (bufferOut == NULL) {
        perror("malloc failed");
        return NULL;
    }
    bufferOut[0] = '\0';  // Ensure an empty string to start

    current = snakeHead;

    // Second pass: Append formatted output
    while (current != NULL) {
        char lineBuffer[256];

        if (strcmp(current->name, "") == 0) {
            // It's a package
            snprintf(lineBuffer, sizeof(lineBuffer), "\nPackage:   %s v%02d.%02d\n------------------------------\n",
                     current->package, current->major, current->minor);
        } else {
            // It's a component
            snprintf(lineBuffer, sizeof(lineBuffer), "Component: %s.%s v%02d.%02d\n",
                     current->package, current->name, current->major, current->minor);
        }

        strcat(bufferOut, lineBuffer);
        current = current->tail;
    }

    return bufferOut;  // Caller must free this memory
}

// -------------------------------------------------------------------------------------------
// This function prints the version information of all registered components.
// It retrieves a dynamically allocated formatted string from toListString(),
// prints it, and then ensures the allocated memory is properly freed.
// --------------------------------------------------------------------------------------------
void PrintListString(void) {
    
    char *buffer = ToListString();  // Get the dynamically allocated version info string
    
    if (buffer == NULL) {
        printf("Error: Unable to retrieve version information.\n");
        return;
    }
    
    printf("%s", buffer);
    
    free(buffer);  // Free the allocated memory to prevent leaks
}