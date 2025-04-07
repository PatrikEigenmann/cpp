/* *******************************************************************************************
 * StringAppend.c - <description>
 *
 * Compile instructions:
 * gcc/clang StringAppend.c -o StringAppend
 * pmake StringAppend.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Mon 2025-04-07 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Regiter the component with the frameworks versioning system.  Version: 00.02
 * ********************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
#include<ctype.h>

#include"StringAppend.h"

#ifdef _WIN32

// --= Windows Section please uncomment what you need! =-- //
#include "..\Samael.h"
#include "..\Samael.ToolBox.h"

#else

// --= MacOS/Linux Section please uncomment what you need! =-- //
#include "../Samael.h"
#include "../Samael.ToolBox.h"

#endif

// -------------------------------------------------------------------------------------------
// regStringAppend - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// Samael.ToolBox.StringAppend.c, which means it will automatically be executed prior to the
// execution of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon as
// the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void regStringAppend(void) {
    // Register the StringAppend package with its version number.
    registerVersion("Samael.ToolBox", "StringAppend", 0, 2);
}

// --------------------------------------------------------------------------------------------
// By encapsulating the process of appending formatted content within this method, we ensure a
// seamless and efficient way to dynamically build strings. This method not only enhances the
// maintainability and readability of your codebase, but also guarantees that formatted content
// is appended consistently and effectively.
// 
// Adopting the append_format method will streamline your string manipulation tasks, fostering
// better organization and flexibility, and ultimately contributing to a more polished and
// efficient product.
// 
// @param char **dest - The destination string to which formatted content will be appended.
// @param const char *format - The format string.
// @param ... - Additional arguments to format and append to the destination string.
// ---------------------------------------------------------------------------------------------
void append_format(char **dest, const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    va_list args_copy;
    va_copy(args_copy, args);
    int size = vsnprintf(NULL, 0, format, args_copy) + 1;
    va_end(args_copy);

    char *temp = malloc(size);
    if (temp == NULL) {
        perror("malloc failed");
        va_end(args);
        return;
    }
    
    vsprintf(temp, format, args);
    va_end(args);

    if (*dest == NULL) {
        *dest = malloc(size);
        if (*dest == NULL) {
            perror("malloc failed");
            free(temp);
            return;
        }
        strcpy(*dest, temp);
    } else {
        *dest = realloc(*dest, strlen(*dest) + size);
        if (*dest == NULL) {
            perror("realloc failed");
            free(temp);
            return;
        }
        strcat(*dest, temp);
    }
    
    free(temp);
}