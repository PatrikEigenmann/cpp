/* *******************************************************************************************
 * jmake.c - Our custom "jmake" program is designed to empower developers by streamlining the
 * build process of Java applications with simplicity and efficiency. Tailored specifically
 * for flexibility, it reads configuration files, interprets instructions, and executes commands
 * to compile and build projects seamlessly. By offering an intuitive and robust solution, our
 * Make program not only enhances productivity but also ensures consistency across various
 * development environments. This tool is an essential asset for any development team, enabling
 * faster turnaround times and improved project management.
 * 
 * Compile information:
 * To avoid unnecessary dependencies to libraries all functions and methods are integraded into this
 * codefile. There for a simple call of the compiler to create an executable without any dependencies
 * is probably the easiest way to create your own pmake tool. If you already have a working pmake, you
 * can use it to compile this code.
 * 
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>

#ifdef _WIN32
    // Include Windows relevant libraries
    #include <io.h>
    
    #define _home() getenv("USERPROFILE")

    /* ----------------------------------------------------------------------------------------------------
     * Windows version:
     * By encapsulating the file existence check within this method, we ensure a seamless and efficient way
     * to verify the presence of files. This method not only enhances the maintainability and readability of
     * your codebase, but also guarantees that file existence checks are performed consistently and reliably.
     * 
     * Adopting the doesFileExist method will streamline your file handling processes, fostering better
     * organization and error handling, and ultimately contributing to a more robust and user-friendly product.
     * 
     * @param char *filename    - The name of the file to check for existence.
     * @param int major         - The major # of the verison number.
     * @param int minor         - The minor # of the version number.
     * @return int              - Returns 1 if the file exists, and 0 if it does not.
     * ---------------------------------------------------------------------------------------------------- */
    int doesFileExist(char *filename, int major, int minor) {

        // First check if the file even exist
        int i = (_access(filename, 0) != -1);

        // If it does,
        if(i > 0) {

            FILE *file;
            char *buffer;
            char version[100] = "\0";
            long file_size;

            // Open the file for reading
            file = fopen(filename, "r");
                        
            // Determine the file size
            fseek(file, 0, SEEK_END);
            file_size = ftell(file);
            rewind(file);
            
            // Allocate memory for the buffer
            buffer = (char *)malloc(sizeof(char) * (file_size + 1));
            
            if (buffer == NULL) {
                printf("Memory allocation failed.\n");
                fclose(file);
                return 1;
            }
            
            // Read the file content into the buffer
            fread(buffer, sizeof(char), file_size, file);
            
            // Null-terminate the string
            buffer[file_size] = '\0';
            
            
            // Close the file
            fclose(file);

            sprintf(version, "%02d.%02d", major, minor);

            i &= (strstr(buffer, version) != NULL);
        }

        return i;
    }
    
    // The command I use under Windows is more. More is the equivalent
    // of the UNIX less command.
    char command[255] = "more ";

    char *PATH = "\\AppData\\Local\\";
#else
    // Include Unix relevant libraries
    #include <unistd.h>

    #define _home() getenv("HOME")

    /* -------------------------------------------------------------------------------------------------
     * MacOS version:
     * By encapsulating the file existence check within this method, we ensure a seamless and efficient
     * way to verify the presence of files. This method not only enhances the maintainability and
     * readability of your codebase, but also guarantees that file existence checks are performed
     * consistently and reliably.
     * 
     * Adopting the doesFileExist method will streamline your file handling processes, fostering better
     * organization and error handling, and ultimately contributing to a more robust and user-friendly product.
     * 
     * @param char *filename    - The name of the file to check for existence.
     * @param int major         - The major # of the verison number.
     * @param int minor         - The minor # of the version number.
     * @return int              - Returns 1 if the file exists, and 0 if it does not.
     * ------------------------------------------------------------------------------------------------- */
    int doesFileExist(char *filename, int major, int minor) {

        int i = (access(filename, F_OK) != -1);

        if(i > 0) {
            FILE *file;
            char *buffer;
            char version[100] = "\0";
            long file_size;

            // Open the file for reading
            file = fopen(filename, "r");
                        
            // Determine the file size
            fseek(file, 0, SEEK_END);
            file_size = ftell(file);
            rewind(file);
            
            // Allocate memory for the buffer
            buffer = (char *)malloc(sizeof(char) * (file_size + 1));
            
            if (buffer == NULL) {
                printf("Memory allocation failed.\n");
                fclose(file);
                return 1;
            }
            
            // Read the file content into the buffer
            fread(buffer, sizeof(char), file_size, file);
            
            // Null-terminate the string
            buffer[file_size] = '\0';
            
            
            // Close the file
            fclose(file);

            sprintf(version, "%02d.%02d", major, minor);

            i &= (strstr(buffer, version) != NULL);
        }

        return i; 
    }

    // The command I use under MacOS/Unix is less. Less is the equivalent
    // of the Windows more command.
    char command[255] = "less ";

    char *PATH = "/.local/share/";
#endif

// -------------------------------------------------------------------------------------------------------
// This structure as a small box labeled “Version”. Inside this box, there are two compartments. One
// compartment is labeled “major”, and the other is labeled “minor”.
//
// These compartments can hold numbers. The number in the “major” compartment represents big changes or
// updates, like a new design or a significant feature. The number in the “minor” compartment represents
// small changes or updates, like a bug fix or a minor improvement.
//
// So, this “Version” box helps us keep track of both big and small updates in an organized way.
// -------------------------------------------------------------------------------------------------------
typedef struct {
    int major;  // Major built
    int minor;  // Minor built
} Version;

/* --------------------------------------------------------------------------------------------------------
 * The ManPage struct is a crucial data structure designed to streamline and enhance the management of
 * manual pages within your applications. It encapsulates all the necessary details of a manual page,
 * including the filename and its corresponding content, into a single, organized unit. This structured
 * approach not only simplifies the creation and modification of documentation but also ensures that your
 * manual pages are consistently and efficiently handled across different platforms.
 * 
 * By leveraging the ManPage struct, your development team can achieve greater efficiency, maintainability,
 * and clarity in managing application documentation, ultimately contributing to a more robust and
 * user-friendly software experience.
 * -------------------------------------------------------------------------------------------------------- */
typedef struct {
    char *filename;
    char *manual;
} ManPage;

const char *FILE_EXTENTION = ".man";

#define MAX_LINE_LENGTH 256

// --------------------------------------------------------------------------------------------------------
// The create_version function is a set of instructions that takes two numbers as input. These numbers
// represent the major and minor parts of a version number, respectively. The function then constructs a
// Version object using these two numbers. The major and minor numbers are stored within this Version object.
// Once this Version object is created, it is then returned by the function. This Version object can be used
// to represent and keep track of the version number of a software or a product. The major part of the version
// usually indicates significant changes or updates, while the minor part indicates smaller updates or bug
// fixes.
//
// @param int major - Major build number.
// @param int minor - Minor build number.
// --------------------------------------------------------------------------------------------------------
Version create_version(int major, int minor) {
    Version v;
    v.major = major;
    v.minor = minor;
    return v;
}

// --------------------------------------------------------------------------------------------------------
// The to_string function is like a translator for the Version object. When you call to_string(v, buffer)
// where v is a Version object and buffer is a space in memory to store a string, you’re essentially asking,
// “Can you translate your version number into a string format?”
//
// In response to this request, the Version object takes its major and minor version numbers, formats them
// into a string that looks like “MM.mm” (where MM is the major version number and mm is the minor version
// number), and then stores this string in the provided buffer.
//
// So, in simple terms, to_string is a way to convert the version number of a Version object into a string
// format.
// --------------------------------------------------------------------------------------------------------
void to_string(Version v, char* buffer) {
    sprintf(buffer, "%02d.%02d", v.major, v.minor);
}

/* --------------------------------------------------------------------------------------------------------
 * By encapsulating the process of appending formatted content within this method, we ensure a seamless and
 * efficient way to dynamically build strings. This method not only enhances the maintainability and
 * readability of your codebase, but also guarantees that formatted content is appended consistently and
 * effectively.
 * 
 * Adopting the append_format method will streamline your string manipulation tasks, fostering better
 * organization and flexibility, and ultimately contributing to a more polished and efficient product.
 * 
 * @param char **dest - The destination string to which formatted content will be appended.
 * @param const char *format - The format string.
 * @param ... - Additional arguments to format and append to the destination string.
 * -------------------------------------------------------------------------------------------------------- */
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

/* -----------------------------------------------------------------------------------------------------
 * By encapsulating the creation of manual pages within this method, we ensure a seamless and efficient
 * process for generating documentation. This not only enhances the maintainability and readability of
 * your codebase, but also guarantees that manual pages are consistently formatted and easily accessible.
 * 
 * Adopting the create_manpage method will streamline your documentation process, fostering better
 * organization and accessibility, and ultimately contributing to a more polished and user-friendly product.
 * 
 * @param char *filenameIn - The filename to the ManPage text file.
 * @param char *manualIn - The content of the ManPage text.
 * ----------------------------------------------------------------------------------------------------- */
void create_manpage(char *filenameIn, char *manualIn, int major, int minor) {

    ManPage mp;

    mp.filename = NULL;
    append_format(&mp.filename, _home());
    append_format(&mp.filename, PATH);
    append_format(&mp.filename, filenameIn);
    append_format(&mp.filename, FILE_EXTENTION);

    mp.manual = NULL;
    append_format(&mp.manual, manualIn);

    if(!doesFileExist(mp.filename, major, minor)) {
        
        FILE *file = fopen(mp.filename, "w");
    
        if (file == NULL) {
            printf("Error opening file!\n");
            return;
        }

        fprintf(file, "%s", mp.manual);

        // Now we can close the file.
        fclose(file);

    }

    strcat(command, mp.filename);
    system(command);
}

/* ----------------------------------------------------------------------------------------------------
 * By encapsulating the detection of help command triggers within this method, we ensure a seamless and
 * efficient way to handle user requests for help or usage information. This method not only enhances
 * the maintainability and readability of your codebase but also guarantees that help commands are
 * consistently and accurately recognized.
 * 
 * Adopting the isHelpTriggered method will streamline your application's user interaction processes,
 * fostering better user experience and accessibility, and ultimately contributing to a more
 * user-friendly product.
 * 
 * @param int argcIn - The number of command-line arguments.
 * @param char *argvIn - The first string of the command-line arguments array.
 * @return int - Returns 1 if the help command is triggered, and 0 otherwise.
 * ---------------------------------------------------------------------------------------------------- */
int isHelpTriggered(int argcIn, char *argvIn) {
    
    /* ------------------------------------------------------- 
     * Help / Manpage is trigger if program call are like:
     *  - <program> or
     *  - <program> -h or
     *  - <program> -H or
     *  - <program> -help or
     *  - <program> -Help
     * ------------------------------------------------------- */
    return (argcIn == 1 ||
        strcmp(argvIn, "-h") == 0 ||
        strcmp(argvIn, "-H") == 0 ||
        strcmp(argvIn, "-help") == 0 ||
        strcmp(argvIn, "-Help") == 0);
}

/* -------------------------------------------------------------------------------------------------------
 * The print_help function is our top-notch guidance feature, crafted to provide users with clear,
 * intuitive instructions for leveraging our command-line utility within the Windows Command Prompt
 * environment. Think of it as your personal guide, always ready to offer step-by-step explanations for
 * each option available in the tool.
 *
 * When users invoke this function, they receive a straightforward and well-structured breakdown of all
 * possible commands, ensuring they can navigate directory listings with ease and efficiency. With familiar
 * flags like -l and -a, the experience feels intuitive, mirroring the user-friendly nature of Unix systems,
 * but optimized for the Windows Command Prompt.
 *
 * In essence, show_help embodies our commitment to user empowerment, making sure every feature is accessible
 * and easily understood. This minimizes learning curves and maximizes productivity. This function is the
 * cornerstone of our user-centric approach, providing instant, reliable support whenever needed. Welcome to
 * a new era of intuitive, efficient command-line interaction.
 * ------------------------------------------------------------------------------------------------------- */
void print_help() {

    // Version control implemented
    Version v = create_version(0, 9);
    
    // The buffer is needed to write
    // the correct formated version number.
    char buffer[6];
    
    // Format the buffer with the
    // correct version number.
    to_string(v, buffer);

    char *manpage = NULL;

    // Write the ManPage style help file.
    append_format(&manpage, "NAME\n");
    append_format(&manpage, "       jmake Version: %s\n", buffer);
    append_format(&manpage, "       Our custom \"jmake\" program is designed to empower Java developers by\n");
    append_format(&manpage, "       streamlining the build process with simplicity and efficiency.\n");
    append_format(&manpage, "       Tailored specifically for flexibility, it reads configuration files,\n");
    append_format(&manpage, "       interprets instructions, and executes commands to compile and build\n");
    append_format(&manpage, "       projects seamlessly. By offering an intuitive and robust solution,\n");
    append_format(&manpage, "       our jmake program not only enhances productivity but also ensures\n");
    append_format(&manpage, "       consistency across various development environments. This tool is\n");
    append_format(&manpage, "       an essential asset for any development team, enabling faster\n");
    append_format(&manpage, "       turnaround times and improved project management.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "SYNOPSIS\n");
    append_format(&manpage, "       jmake <makefile>\n");
    append_format(&manpage, "       jmake <-h\\-help\\-H\\-Help>\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "DESCRIPTION\n");
    append_format(&manpage, "       <makefile> The name of the makefile with the build instructions\n");
    append_format(&manpage, "       to be processed.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           Example Makefile myproject.jmake:\n");
    append_format(&manpage, "           ---------------------------------------\n");
    append_format(&manpage, "           # Define the java compiler, if left empty default compiler is used.\n");
    append_format(&manpage, "           javac=\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           # Define the classpath. Unused libraries or projects can be simply commented out.\n");
    append_format(&manpage, "           classpath=.\n");
    append_format(&manpage, "           /path/to/Project1\n");
    append_format(&manpage, "           #/path/to/Project2\n");
    append_format(&manpage, "           /path/to/lib1\n");
    append_format(&manpage, "           #/path/to/lib2\n");
    append_format(&manpage, "           # end of classpath  <- empty line or \"end of classpath\" indicates the end of classpath.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           #Or you can define the classpath externally in the classpath.txt file.\n");
    append_format(&manpage, "           classpath=classpath.txt\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           # Source files to compile, if left empty it will compile all java files\n");
    append_format(&manpage, "           # in the active folder by using *.java. or you can list the files to compile.\n");
    append_format(&manpage, "           # Or you can let jmake find all .java files in the active folder and subfolders.\n");
    append_format(&manpage, "           # by using the @<source_file>.txt\n");
    append_format(&manpage, "           src=\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           # OR\n");
    append_format(&manpage, "           src=Class1.java Class2.java Class3.java (optional)\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "           # OR\n");
    append_format(&manpage, "           src=@sources.txt (optional)\n");
    append_format(&manpage, "           ---------------------------------------\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "       -h, -help -H -Help\n");
    append_format(&manpage, "              Display this help and exit.\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "AUTHOR\n");
    append_format(&manpage, "       Patrik Eigenmann (p.eigenmann@gmx.net)\n");
    append_format(&manpage, "\n");
    append_format(&manpage, "COPYRIGHT\n");
    append_format(&manpage, "      Copyright 2024 Free Software Foundation, Inc. License GPLv3+:\n");
    append_format(&manpage, "      GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\n");
    append_format(&manpage, "      This is free software: you are free to change and redistribute it.\n");
    append_format(&manpage, "      There is NO WARRANTY, to the extent permitted by law.\n");

    // Create the manpage in the file
    create_manpage("pmake", manpage, v.major, v.minor);

    // Free up the memory.
    free(manpage);
}

/* ------------------------------------------------------------------------------------------------
 * The process_makefile function is a pivotal component of our custom "Make" program, designed to
 * streamline the build process by reading and executing commands from a specified makefile. This
 * function ensures efficient parsing and execution of build instructions, enhancing productivity
 * and simplifying project management for developers.
 *
 * @param filename  The name of the makefile to be processed. This file contains the build instructions
 *                  to be executed.
 * ------------------------------------------------------------------------------------------------- */
void process_makefile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    char javac[MAX_LINE_LENGTH] = "";
    char classpath[MAX_LINE_LENGTH * 4] = "";
    char src[MAX_LINE_LENGTH * 4] = "";
    bool in_classpath = false;
    
    while (fgets(line, sizeof(line), file)) {
        // Trim newline character
        line[strcspn(line, "\n")] = 0;
                
        // Parse javac directive
        if (strncmp(line, "javac=", 6) == 0 && !in_classpath) {
            strcpy(javac, line + 6);
            if (strlen(javac) == 0) {
                strcpy(javac, "javac"); // Default to system javac
            }
        }

        // Parse classpath directive
        // Start processing a classpath block
        if (strncmp(line, "classpath=", 10) == 0) {
            in_classpath = true;
            strcpy(classpath, line + 10);
            if (classpath[0] == '@') {
                // Handle @ directive for classpath
                FILE *classpathFile = fopen(classpath + 1, "r");
                if (classpathFile) {
                    char path[MAX_LINE_LENGTH];
                    classpath[0] = '\0'; // Reset classpath
                    while (fgets(path, sizeof(path), classpathFile)) {
                        path[strcspn(path, "\n")] = 0; // Trim newline characters
                        if (path[0] == '#' || path[0] == '\0') continue; // Skip comments/empty lines
                        if (strlen(classpath) > 0) strcat(classpath, ":");
                        strcat(classpath, path);
                    }
                    fclose(classpathFile);
                }
                in_classpath = false; // Single-line directive is complete
            }
        } 
        // Continue processing multi-line classpath block
        else if (in_classpath) {
            if (line[0] == '\0' || strncmp(line, "javac=", 6) == 0
                || strncmp(line, "src=", 4) == 0
                || strcmp(line, "# end of classpath") == 0) {
                in_classpath = false; // End of classpath block
            } else {
                if (line[0] != '#') { // Skip comments/empty lines
                    if (strlen(classpath) > 0) strcat(classpath, ":");
                    strcat(classpath, line);
                }
            }
        }
        
        // Parse src directive
        else if (strncmp(line, "src=", 4) == 0 && !in_classpath) {
            strcpy(src, line + 4);
            if (strlen(src) == 0) {
                strcpy(src, "*.java"); // Default to all .java files
            } else if (src[0] == '@') {
                // Generate sources.txt file
                char create[MAX_LINE_LENGTH];
                snprintf(create, sizeof(create), "find . -name \"*.java\" > %s", src + 1);
                system(create);
            }
        }
    }
    
    fclose(file);

    char *command = NULL;

    append_format(&command, "%s ", javac);

    if(classpath[0] != '\0')
        append_format(&command, "-cp %s ", classpath);

    if(src[0] != '\0')
        append_format(&command, "%s ", src);

    printf("Compiling command:\n");
    printf("%s\n", command);

    // Execute the command
    int result = system(command);

    // clean up
    if(src[0] == '@') {
        char del[MAX_LINE_LENGTH];
        snprintf(del, sizeof(del), "rm %s", src + 1);
        system(del);
    }

    if (result != 0) {
        fprintf(stderr, "Command failed: %s\n", command);
        exit(EXIT_FAILURE);
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
    // Check if the help is triggered.
    if(isHelpTriggered(argc, argv[1])) {
        print_help();
        return 1;
    }

    process_makefile(argv[1]);
    return EXIT_SUCCESS;
}