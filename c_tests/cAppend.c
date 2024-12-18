/* **********************************************************************************************
 * The cAppend.c program exemplifies the dynamic handling and manipulation of strings within
 * functions, showcasing flexible string operations and memory management. Designed as a foundational
 * test, this program highlights efficient string appending techniques, crucial for building robust
 * and adaptable software solutions.
 * 
 * Key Components:
 * 
 * - Functionality: Demonstrates the ability to augment a base string with user-provided input,
 *   culminating in the display of the modified string. This showcases seamless integration and
 *   manipulation of strings within a structured framework.
 * 
 * - Versatility: Provides cross-platform compile instructions, ensuring compatibility and ease of
 *   use across both Windows and macOS systems.
 * 
 * - Clarity: The concise and well-documented codebase enhances maintainability and readability,
 *   making it an excellent example for learning and demonstrating string handling in C.
 * 
 * This program serves as an educational tool, and hopefully it lays the groundwork for more
 * complex string operations, ultimately contributing to the development of efficient and reliable
 * software applications.
 *
 * Compile instructions:
 * For Windows  -> gcc cAppend.c -o cAppend
 * For MacOS    -> clang cAppend.c -o cAppend
 * pmake cAppend.makefile
 * -----------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * -----------------------------------------------------------------------------------------------
 * Sun 2024-02-04 File created.                                                     Version: 00.01
 * ***********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// **********************************************************************************************
// The foo function demonstrates the dynamic enhancement of a foundational string by appending a
// user-provided value. This process culminates in the display of the augmented string, showcasing
// the seamless integration of flexible string manipulation within our robust framework.
//
// @param String test - User provided test string.
// ***********************************************************************************************
void foo(char *test) {
    char string[100] = "~/Development/";

    strcat(string, test);
    
    printf("String: %s.txt\n", string);
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
int main() {

    foo("mytest");
    return 0;
}