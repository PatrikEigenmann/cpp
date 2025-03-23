/* *******************************************************************************************
 * samael.c - This file serves as an umbrella header for a shared library. It aggregates and
 * provides access to all the necessary module headers, offering a single point of inclusion
 * for the library's functionality.
 *
 * By including this file, users gain access to all components of the library without needing
 * to include each module individually. This approach simplifies integration, ensures
 * modularity, and provides a consistent interface for the library's features.
 *
 * Updates to the library (e.g., adding new modules) can be seamlessly reflected here, allowing
 * users to benefit from the extended functionality without modifying their code.
 *
 * Best practices:
 * - Maintain logical organization of modules within the library.
 * - Ensure modular independence of individual headers included here.
 * - Document high-level functionality provided by the library.
 * 
 * Compiler instructions:
 * 4) gcc -shared -o bin/libsamael.so samael.c utility/cManPage.c utility/cProgress.c
 *                   utility/cVersion.c
 * Or pmake samael.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Sat 2025-03-22 File created.                                                 Version: 00.01
 * Sat 2025-03-23 Folder update: From util to utility.                          Version: 00.02
 * ********************************************************************************************/

#include "samael.h"

/* -------------------------------------------------------------------------------------------
 * Note: This file currently does not contain any additional implementation.
 * ------------------------------------------------------------------------------------------- */