/* *******************************************************************************************
 * Samael.Chronicle.c - Samael.Chronicle serves as the guardian of history, preserving the
 * evolution and progression of a project through meticulous version control. It offers a
 * robust suite of tools to track changes, manage revisions, and maintain the integrity of
 * development workflows. Designed with precision, this module ensures that every iteration
 * is documented and easily retrievable for reference or rollback. Samael.Chronicle emphasizes
 * collaboration and transparency, enabling seamless integration across team environments. By
 * maintaining a comprehensive record of transformations, it provides clarity and insight into
 * the development process. Whether for individual projects or large-scale initiatives, this
 * module safeguards the legacy of code while empowering developers to move forward with
 * confidence. Samael.Chronicle stands as a testament to the importance of preserving progress
 * and celebrating innovation.
 *
 * Compile instructions:
 * gcc -shared Samael.Chronicle.c -o bin/libSamael.Chronicle.so
 * or pmake Samael.Chronicle.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-03-26 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Register package Chronicle with it's version number.          Version: 00.02
 * Sun 2025-04-06 Added Componet Version to the package Chronicle.              Version: 00.03
 * ********************************************************************************************/

#include "Samael.h"
#include "Samael.Chronicle.h"

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
__attribute__((constructor)) void regChronicle(void) {
    // Register the version information for the Samael.Chronicle component
    registerVersion("Samael.Chronicle", "", 0, 3);
}