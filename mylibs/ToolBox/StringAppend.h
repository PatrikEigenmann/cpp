/* *******************************************************************************************
 * StringAppend.h - <description>
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Mon 2025-04-07 File created.                                                 Version: 00.01
 * Sun 2025-04-06 Regiter the component with the frameworks versioning system.  Version: 00.02
 * ********************************************************************************************/
#ifndef STRING_APPEND_H
#define STRING_APPEND_H

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
void regStringAppend(void);

/* ----------------------------------------------------------------------------------------------------
 * By encapsulating the process of appending formatted content within this method, we ensure a seamless
 * and efficient way to dynamically build strings. This method not only enhances the maintainability and
 * readability of your codebase, but also guarantees that formatted content is appended consistently and
 * effectively.
 * 
 * Adopting the append_format method will streamline your string manipulation tasks, fostering better
 * organization and flexibility, and ultimately contributing to a more polished and efficient product.
 * 
 * @param char **dest - The destination string to which formatted content will be appended.
 * @param const char *format - The format string.
 * @param ... - Additional arguments to format and append to the destination string.
 * ---------------------------------------------------------------------------------------------------- */
void append_format(char **dest, const char *format, ...);

#endif