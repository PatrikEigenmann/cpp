/* *******************************************************************************************
 * jmake.c - <description>
 *
 * Compile instructions:
 * gcc/clang jmake.c -o jmake
 * pmake jmake.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Mon 2025-03-17 File created.                                                 Version: 00.01
 * -------------------------------------------------------------------------------------------
 * To Do's:
 * ********************************************************************************************/
#include<stdio.h>

#ifdef _WIN32
// --= Windows Section please uncomment what you need! =-- //
//    #include "..\mylibs\cVersion.h"
//    #include "..\mylibs\cManPage.h"
//    #include "..\mylibs\cProgress.h"

#else
// --= MacOS/Linux Section please uncomment what you need! =-- //
//    #include "../mylibs/cVersion.h"
//    #include "../mylibs/cManPage.h"
//    #include "../mylibs/cProgress.h"

#endif

/* ---------------------------------------------------------------------------------------------------------
 * The print_help function is our top-notch guidance feature, crafted to provide users with clear, intuitive
 * instructions for leveraging our command-line utility within the Windows Command Prompt environment.
 * Think of it as your personal guide, always ready to offer step-by-step explanations for each option
 * available in the tool.
 *
 * When users invoke this function, they receive a straightforward and well-structured breakdown of all possible
 * commands, ensuring they can navigate directory listings with ease and efficiency. With familiar flags
 * like -l and -a, the experience feels intuitive, mirroring the user-friendly nature of Unix systems, but
 * optimized for the Windows Command Prompt.
 *
 * In essence, show_help embodies our commitment to user empowerment, making sure every feature is accessible
 * and easily understood. This minimizes learning curves and maximizes productivity. This function is the
 * cornerstone of our user-centric approach, providing instant, reliable support whenever needed. Welcome to a
 * new era of intuitive, efficient command-line interaction.
 * --------------------------------------------------------------------------------------------------------- */
void print_help() {
    
    // Version control implemented
    Version v = create_version(0, 1);
        
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    char *manpage = NULL;

    // Write the ManPage style help file.
    append_format(&manpage, "NAME\n");
    append_format(&manpage, "      <c program> Version: %s\n", buffer);
    append_format(&manpage, "      \n");
    append_format(&manpage, "      \n");
    append_format(&manpage, "\n");
    append_format(&manpage, "SYNOPSIS\n");
    append_format(&manpage, "      <c program> <parameters>\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "DESCRIPTION\n");
    append_format(&manpage, "      \n");
    append_format(&manpage, "      \n");
    append_format(&manpage, "\n");
    append_format(&manpage, "      -h, -H, -help\n");
    append_format(&manpage, "                    Display this help message.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "AUTHOR\n");
    append_format(&manpage, "      Patrik Eigenmann (p.eigenmann@gmx.net).\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "COPYRIGHT\n");
    append_format(&manpage, "      Copyright 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    append_format(&manpage, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    append_format(&manpage, "      This is free software: you are free to change and redistribute it.\n");
    append_format(&manpage, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Create the manpage in the file ~/.local/share/<c program>.man
    create_manpage("<c program>", manpage, v.major, v.minor);
    
    // Free up the memory.
    free(manpage);
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
    
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    FILE *makefile = fopen("jmakefile", "r");
    if (!makefile) {
        perror("Failed to open makefile");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char javac[MAX_LINE_LENGTH] = "javac";
    char classpath[MAX_LINE_LENGTH] = ".";
    char src[MAX_LINE_LENGTH] = "*.java";

    while (fgets(line, sizeof(line), makefile)) {
        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        // Parse javac directive
        if (strncmp(line, "javac=", 6) == 0) {
            strcpy(javac, line + 6);
            if (strlen(javac) == 0) {
                strcpy(javac, "javac"); // Default to system javac
            }
        }

        // Parse classpath directive
        else if (strncmp(line, "classpath=", 10) == 0) {
            strcpy(classpath, line + 10);
            if (classpath[0] == '\0') {
                strcpy(classpath, ".");
            } else if (classpath[0] == '@') {
                // Read from file (e.g., classpath.txt)
                FILE *classpathFile = fopen(classpath + 1, "r");
                if (classpathFile) {
                    char path[MAX_LINE_LENGTH];
                    classpath[0] = '\0'; // Reset classpath
                    while (fgets(path, sizeof(path), classpathFile)) {
                        path[strcspn(path, "\n")] = 0;
                        if (path[0] == '#' || path[0] == '\0') continue; // Skip comments/empty lines
                        if (strlen(classpath) > 0) strcat(classpath, ":");
                        strcat(classpath, path);
                    }
                    fclose(classpathFile);
                }
            }
        }

        // Parse src directive
        else if (strncmp(line, "src=", 4) == 0) {
            strcpy(src, line + 4);
            if (strlen(src) == 0) {
                strcpy(src, "*.java"); // Default to all .java files
            } else if (src[0] == '@') {
                // Generate sources.txt file
                char command[MAX_LINE_LENGTH];
                snprintf(command, sizeof(command), "find . -name \"*.java\" > %s", src + 1);
                system(command);
            }
        }
    }

    fclose(makefile);

    // Construct and execute the javac command
    char command[MAX_LINE_LENGTH * 4];
    snprintf(command, sizeof(command), "%s -cp %s %s", javac, classpath, src);
    printf("Executing: %s\n", command);
    int result = system(command);

    return result;
}

*/
