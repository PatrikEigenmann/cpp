/* ******************************************************************************************************************
 * cCase.c - This example demonstrates how to use the case keyword within a switch statement to execute specific code
 * blocks based on the value of a variable. It’s a powerful way to manage control flow in a clean and readable
 * manner.
 *
 * compiler instructions:
 * If you use my own tool "pmake" to compile this sample program its: pmake <c program>.makefile
 * If you use the GNU cross=platform compiler: gcc <c program>.c -o <c program>
 * If you use the Clang compiler: clang <c program>.c -o <c program>
 * ------------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * -------------------------------------------------------------------------------------------------------------------
 * Thu 2024-12-05 File created.                                                                         Version: 00.01
 * -------------------------------------------------------------------------------------------------------------------
 * To Do's:
 * *******************************************************************************************************************/

#include<stdio.h>
#include <time.h>
#include <string.h>

// Function to check if the current date is a holiday
int isHoliday(int day, int month) {
    
    // Example: New Year's Day (January 1)
    if (day == 1 && month == 1) {
        return 1;
    }
    
    // Example: Independence Day (July 4)
    if (day == 4 && month == 7) {
        return 1;
    }
    
    // Example: Christmas Day (December 25)
    if (day == 25 && month == 12) {
        return 1;
    }
    
    // Add more holidays as needed
    return 0;
}

/* ------------------------------------------------------------------------------------------------------------------
 * The getTodayInfo() function is designed to provide real-time information about the current date, the day of the
 * week, and whether today is a holiday. It begins by accessing the system's clock to fetch the current date and time,
 * ensuring that the information is always up to date. It then identifies the day of the week, such as Sunday or
 * Monday, by leveraging the tm structure from the time.h library. After determining the day, the function checks if
 * today is a recognized holiday by comparing the current date against a predefined list of holidays. This check helps
 * in adjusting plans or operations accordingly. The function outputs the gathered information in a clear and concise
 * manner, making it easy for users to understand the current date, the day, and whether it's a holiday. Overall,
 * getTodayInfo() enhances the system's ability to provide temporal context, supporting better decision-making and
 * planning. By integrating real-time date checks and holiday recognition, it becomes an essential tool for any
 * application that requires awareness of the current temporal parameters. This function demonstrates efficiency and
 * precision in managing and presenting date-related information seamlessly.
 * ------------------------------------------------------------------------------------------------------------------*/
void getTodayInfo() {
    // Get the current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    // Print the current date
    printf("Today's date is: %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
    // Determine the day of the week
    char *daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Today is: %s\n", daysOfWeek[tm.tm_wday]);
    
    // Check if today is a holiday
    if (isHoliday(tm.tm_mday, tm.tm_mon + 1)) {
        printf("Today is a holiday!\n");
    } else {
        printf("Today is not a holiday.\n");
    }
}


/* ---------------------------------------------------------------------------------------------------------------
 * main - In the vast, uncharted realms of cyberspace, there exists a function. Not just any function, but the main
 * function. It is the gatekeeper, the sentinel that stands at the threshold of every C and C++ program. It is the
 * beginning and the end, the alpha and the omega.
 *
 * @param int argc     - Command argument count
 * @param char **argv  - Command argument strings
 * @return             - 0 if the program executes successfully. If the program encounters an error that warrants
 *                       termination, you can return a different integer value (commonly 1 or another non-zero value)
 *                       to indicate the type of error.
 * --------------------------------------------------------------------------------------------------------------- */
int main(int argc, char **argv) {
    
    /*
     * This example demonstrates how to use the case keyword within a switch statement to execute
     * specific code blocks based on the value of a variable. It’s a powerful way to manage
     * control flow in a clean and readable manner.
     */

    // Initialize a variable to represent a day of the week (1 = Monday, 2 = Tuesday, ..., 7 = Sunday)
    // Initializing 'day' ensures the variable starts with a known value, critical for predictable program
    // behavior.
    int day = 0; 
    
    // Use a switch statement to determine the name of the day based on the value of 'day'
    switch (day) {
        
        // Case for Monday
        case 1:
            printf("Monday\n");
            break; // Exit the switch block

        
        // Case for Tuesday
        case 2:
            printf("Tuesday\n");
            break; // Exit the switch block

        
        // Case for Wednesday
        case 3:
            printf("Wednesday\n");
            break; // Exit the switch block

        
        // Case for Thursday
        case 4:
            printf("Thursday\n");
            break; // Exit the switch block

        
        // Case for Friday
        case 5:
            printf("Friday\n");
            break; // Exit the switch block
        
        
        // Case for Saturday
        case 6:
            printf("Saturday\n");
            break; // Exit the switch block

        
        // Case for Sunday case 7:
            printf("Sunday\n");
            break; // Exit the switch block
        
        // Default case if 'day' doesn't match any of the above cases
        default:
            getTodayInfo();
            break; // Exit the switch block
    }
    
    // Return 0 to indicate the program ended successfully
    return 0;
}