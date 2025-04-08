/* *******************************************************************************************
 * Samael.Entanglement.h - Samael.Entanglement is a module dedicated to mastering
 * the intricate world of array and list operations. It provides a comprehensive suite of tools
 * for sorting, searching, and manipulating data structures with precision and efficiency.
 * Designed for versatility, it seamlessly integrates with other modules while maintaining
 * independent robustness. Samael.Entanglement emphasizes performance optimization, ensuring
 * that even the most complex operations are handled swiftly and effectively. Its capabilities
 * extend beyond basic utilities, enabling developers to implement sophisticated algorithms like
 * quicksort or quickfind with ease. Whether tackling large datasets or intricate data
 * relationships, this module empowers users to untangle complexity and find clarity.
 * Samael.Entanglement brings order to chaos, transforming raw collections into structured,
 * actionable insights.
 * 
 * Compile instructions:
 * gcc -shared Samael.Entanglement.c -o bin/libSamael.Entanglement.so
 * or pmake Samael.Entanglement.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Wed 2025-03-26 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Register package Entanglement with it's version number.       Version: 00.02
 * Mon 2025-04-07 Implemented the new Samael naming convention.                 Version: 00.03
 * Tue 2025-04-08 Bug Fixed: RegisterVersion(Samael.Entanglement", "", 0, 4);   Version: 00.04
 * ********************************************************************************************/

#ifndef SAMAEL_ENTANGLEMENT_H
#define SAMAEL_ENTANGLEMENT_H

#ifdef _WIN32
    // -------------------------------------------------------------------------------------------
    // Include Samael.Entanglement headers for the library's functionality under Windows.
    // -------------------------------------------------------------------------------------------

#else
    // -------------------------------------------------------------------------------------------
    // Include Samael.Entanglement headers for the library's functionality under Unix systems.
    // -------------------------------------------------------------------------------------------

#endif

// -------------------------------------------------------------------------------------------
// RegEntanglement - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// (Samael.Entanglement.c), which means it will automatically be executed prior to the execution
// of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon
// as the module is loaded.
// -------------------------------------------------------------------------------------------
void RegEntanglement(void);

#endif