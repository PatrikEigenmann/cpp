/* *******************************************************************************************
 * StringAppend.c - This file contains the implementation of the AppendFormat function. A very
 * appreciated function in the coding community in various languages. Oldschool C programmers
 * will remember the function as sprintf. But in the Samael framework, one of the main goals is
 * to provide a clean and concise API throughout various programming languages and paradigms.
 * That is why we have decided to add this function in the Samael framework instead of using
 * sprintf.
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Mon 2025-04-07 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Regiter the component with the frameworks versioning system.  Version: 00.02
 * Mon 2025-04-07 Changed All names to new Samael naming convention.            Version: 00.03
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
// RegStringAppend - Automatically registers this component's version information with the
// versioning system of the Samael framework.
//
// This function is marked with the constructor attribute in the implementation file
// Samael.ToolBox.StringAppend.c, which means it will automatically be executed prior to the
// execution of the main() function. This pre-main invocation is part of the automatic versioning
// mechanism, ensuring that the version details for this component are registered as soon as
// the module is loaded.
// -------------------------------------------------------------------------------------------
__attribute__((constructor)) void RegStringAppend(void) {
    // Register the StringAppend package with its version number.
    RegisterVersion("Samael.ToolBox", "StringAppend", 0, 3);
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
// @param char **destInOut      - The destination string to which formatted content will be appended.
// @param const char *formatIn  - The format string.
// @param ...                   - Additional arguments to format and append to the destination string.
// ---------------------------------------------------------------------------------------------
void AppendFormat(char **destInOut, const char *formatIn, ...) {
    
    // Check if the destination string and format string are not null
    // and handle the case where destInOut is NULL
    // to prevent dereferencing a null pointer.
    if (destInOut == NULL || formatIn == NULL) {
        return;  // Prevent null pointer dereference
    }

    va_list args;               // Initialize the variable argument list
    va_start(args, formatIn);   // Start processing the variable arguments

    va_list args_copy;          // Create a copy of the argument list for size calculation
    va_copy(args_copy, args);   // Copy the argument list for size calculation
    int size = vsnprintf(NULL, 0, formatIn, args_copy) + 1;  // Determine required buffer size
    va_end(args_copy);         // End the copy of the argument list

    // Check if size is valid and handle formatting error gracefully
    // vsnprintf returns a negative value on error, so we check for that
    // and ensure size is positive before proceeding.
    if (size <= 0) {
        va_end(args);   // End the original argument list
        return;         // Handle formatting error gracefully
    }

    char *temp = malloc(size);  // Allocate memory for the formatted string
        
    // Check if memory allocation was successful
    // and handle allocation failure gracefully
    // by freeing the allocated memory and returning.
    if (!temp) {
        perror("malloc failed");    // Handle memory allocation failure
        va_end(args);               // End the original argument list
        return;                     // Return to avoid dereferencing a null pointer
    }

    // Format the string and store it in the allocated memory
    // Check if vsnprintf was successful and handle formatting error gracefully
    // by freeing the allocated memory and returning.
    vsnprintf(temp, size, formatIn, args);
    va_end(args);                           // End the original argument list

    // Check if the destination string is NULL
    // and handle the case where destInOut is NULL
    // to prevent dereferencing a null pointer.
    if (*destInOut == NULL) {
        *destInOut = temp;                  // Assign directly if destination is empty
    } else {
        // If the destination string is not NULL, we need to append the new string
        // Check if realloc was successful and handle allocation failure gracefully
        // by freeing the allocated memory and returning.
        size_t current_length = strlen(*destInOut);
        
        // Allocate new memory for the concatenated string
        // Check if realloc was successful and handle allocation failure gracefully
        // by freeing the allocated memory and returning.
        char *new_buffer = realloc(*destInOut, current_length + size);
        
        // Check if realloc was successful and handle allocation failure gracefully
        // by freeing the allocated memory and returning.
        // If realloc fails, it returns NULL and the original memory is not freed.
        if (!new_buffer) {
            perror("realloc failed");       // Handle memory allocation failure
            free(temp);                     // Free the temporary buffer
            return;                         // Return to avoid dereferencing a null pointer
        }

        // Append the formatted string to the destination string
        // Check if the destination string is NULL
        // and handle the case where destInOut is NULL
        // to prevent dereferencing a null pointer.
        *destInOut = new_buffer;

        // Append the formatted string to the destination string
        // Check if strcat was successful and handle concatenation error gracefully
        // by freeing the allocated memory and returning.
        strcat(*destInOut, temp);

        // Free the temporary buffer as it's no longer needed
        // Check if temp is NULL
        // and handle the case where temp is NULL
        // to prevent dereferencing a null pointer.
        free(temp);
    }
}