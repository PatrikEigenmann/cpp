/* ******************************************************************************************************
 * The cArg.c program is a straightforward yet powerful demonstration of handling command-line arguments
 * in C. Designed to test and showcase effective string manipulation, this program highlights key
 * techniques for processing user inputs directly from the command line, essential for building interactive
 * and user-friendly applications.
 * 
 * This program serves as an excellent educational tool and a foundation for developing more complex
 * command-line applications, ultimately contributing to a more polished and efficient software development
 * process.
 * 
 * Compile instructions:
 * gcc/clang cArg.c -o cArg
 * pmake cArg.makefile 
 * -------------------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------------------
 * Sun 2024-02-04 File created.                                                             Version: 00.01
 * Tue 2024-11-05 Crossplatform tests.                                                      Version: 00.02
 * Tue 2025-01-22 Header comment GitHub URL updated.                                        Version: 00.03
 * *******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ----------------------------------------------------------------------------------------------
 * By encapsulating the process of converting strings to lowercase within this method, we ensure
 * a seamless and efficient way to standardize text. This method not only enhances the maintainability
 * and readability of your codebase, but also guarantees that string transformations are performed
 * consistently and reliably.
 * 
 * Adopting the toLowerCase method will streamline your text processing tasks, fostering better
 * organization and uniformity, and ultimately contributing to a more polished and user-friendly
 * product.
 * 
 * @param char *str - The string to be converted to lowercase.
 * ---------------------------------------------------------------------------------------------- */
void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

// ---------------------------------------------------------------------------------------------
// main - The main function is the starting point of a C or C++ program, where execution begins.
// This version of the main function allows the program to take command-line arguments when it
// runs. The function typically returns an numbered value to the operating system, often zero
// to signify successful execution.
//
// @param argc  The number of command-line arguments.
// @param argv  The array of command-line arguments.
// @return      0 on successful completion, 1 on error.
// ----------------------------------------------------------------------------------------------
int main (int argc, char **argv) {

    printf("Command Line Argument Count: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        
        char *argument = argv[i];
        toLowerCase(argument);

        printf("Command Line Argument: %s\n", argument);
    }
    return 0;
}