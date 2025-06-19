/* *******************************************************************************************
 * markdown.h - This file serves as an umbrella header for a shared library. It aggregates and
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
 * 1) cd md4c
 * 2) gcc -c -fPIC md4c.c md4c-html.c entity.c
 * 3) cd ..
 * 4) gcc -shared -o bin/libmarkdown.so md4c/md4c.o md4c/md4c-html.o md4c/entity.o
 * -Wl,-install_name,/Users/patrik/Development/cpp/mylibs/bin/libmarkdown.so
 * 
 * Or pmake markdown.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Sat 2025-03-22 File created.                                                 Version: 00.01
 * ********************************************************************************************/

#ifndef MARKDOWN_H
#define MARKDOWN_H

#ifdef _WIN32
    // --------------------------------------- Windows -------------------------------------------
    /* *******************************************************************************************
     * Include all the necessary module headers for the shared library.
     * ********************************************************************************************/
    #include "md4c\entity.h"
    #include "md4c\md4c-html.h"
    #include "md4c\md4c.h"
#else
    // --------------------------------------- Unix ----------------------------------------------
    /* *******************************************************************************************
     * Include all the necessary module headers for the shared library.
     * ********************************************************************************************/
    #include "md4c/entity.h"
    #include "md4c/md4c-html.h"
    #include "md4c/md4c.h"

#endif

#endif