/* *******************************************************************************************
 * Version.h - This file defines a structure for managing version information within the Samael
 * framework. It includes the necessary fields for package name, component name, major and minor
 * version numbers, and a pointer to the next version entry in a linked list. This structure is
 * essential for maintaining a comprehensive version history and ensuring that all components
 * are properly registered and organized within the framework.
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Sun 2025-04-06 File created.                                                 Version: 00.01
 * Mon 2025-04-07 Changed All names to new Samael naming convention.            Version: 00.02
 * Tue 2025-04-08 Bug Fixed: Call of ToString(versionIn, buffer); L116          Version: 00.03
 * ********************************************************************************************/

#ifndef VERSION_H
#define VERSION_H

// -------------------------------------------------------------------------------------------
// Struct Version:
// This structure represents a version entry within Samael's framework. It serves as an essential 
// building block for version tracking and organizing components at runtime.
//
// Each version entry contains four key attributes:
// - The package name, specifying the broader category the component belongs to.
// - The component name, identifying the specific module within the package.
// - The major version number, representing significant changes in functionality.
// - The minor version number, indicating smaller revisions or refinements.
// - A pointer to the next version enty in the linked list, allowing for dynamic version management.
//
// These version entries are connected in a linked list, allowing the framework to dynamically 
// manage registered components, sort them into structured hierarchies, and retrieve version 
// information efficiently. The linked list ensures that all components register automatically,
// maintaining a well-organized version tracking system.
//
// Samael uses this approach to provide structured version management, enabling applications 
// to detect compatibility issues, recommend upgrades, and ensure stability across different 
// framework versions.
// -------------------------------------------------------------------------------------------
typedef struct Version {
    char package[100];   // Package name
    char name[100];      // Component name
    int major;
    int minor;
    struct Version* tail;  // Linked list pointer
} Version;

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
void RegVersion();

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
Version* CreateVersion(char* packageIn, char* nameIn, int majorIn, int minorIn);

// -------------------------------------------------------------------------------------------
// This function creates a formatted string representing the version information of the given
// Version entry. The formatted string includes the package name, component name, major and
// minor version numbers with two digits, and is stored in the provided buffer.
//
// @param versionIn - The Version entry to be formatted.
// @param bufferIn  - The buffer to store the formatted string.
// -------------------------------------------------------------------------------------------
void ToString(Version* versionIn, char* bufferIn);

// -------------------------------------------------------------------------------------------
// This function prints the version information of the given Version entry to the standard
// output. It formats the output to include the package name, component name, major and minor
// version numbers, and the total number of versions registered in the linked list.
//
// @param versionIn - The Version entry to be printed.
// -------------------------------------------------------------------------------------------
void PrintVersion(Version* versionIn);

#endif