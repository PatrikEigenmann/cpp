/* ******************************************************************************************************************
 * cBreak.c - In C programming, the break keyword is a crucial control statement used to alter the flow of loops and
 * switch statements. Its primary function is to terminate the execution of the closest enclosing loop or switch
 * statement, allowing the program to exit the loop or switch immediately and continue with the next statement after
 * the loop or switch.
 *
 * For instance, consider a scenario where you’re iterating over a list of items, and you want to stop the iteration
 * as soon as you find a particular item. The break statement becomes invaluable here, as it prevents unnecessary
 * iterations once the condition is met.
 *
 * compiler instructions:
 * If you use my own tool "pmake" to compile this sample program its: pmake cBreak.makefile
 * If you use the GNU cross=platform compiler: gcc cBreak.c -o cBreak
 * If you use the Clang compiler: clang cBreak.c -o cBreak
 * ------------------------------------------------------------------------------------------------------------------
 * Author:       Patrik Eigenmann
 * eMail:        p.eigenmann@gmx.net
 * -------------------------------------------------------------------------------------------------------------------
 * Thu 2025-12-05 File created.                                                                         Version: 00.01
 * -------------------------------------------------------------------------------------------------------------------
 * To Do's:
 * *******************************************************************************************************************/
#include<stdio.h>

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
int main (int argc, char **argv) {
    
    /*
     * This structure showcases the break keyword, which is a crucial control statement in C. It allows you to
     * exit loops early based on specific conditions, providing better control over the program flow.
     */
    
    // Initialize an integer variable 'i' to 0
    // It's important to initialize 'i' to ensure it starts with a known value.
    // Uninitialized variables can lead to unpredictable behavior and bugs.
    int i = 0;
    
    // Start a while loop that continues as long as 'i' is less than 10
    while (i < 10) {
        // Print the current value of 'i'
        // This helps us track the value of 'i' during each iteration.
        printf("The iterator is: %d\n", i);
        
        // Check if 'i' is equal to 8
        // This condition allows us to control when to exit the loop early.
        if(i == 8) {
            
            // Print a message indicating the loop is being interrupted.
            // This provides clear feedback on why the loop is stopping.
            printf("   Iterator reached %d.\n   While loop interrupted.\n", i);
            
            // Break out of the loop when 'i' equals 8
            // The 'break' statement is crucial for exiting the loop prematurely.
            // Without it, the loop would continue until 'i' reaches 10.
            break;
        }
        
        // Increment 'i' by 1
        // Incrementing 'i' ensures the loop progresses and eventually terminates.
        // Without incrementing, the loop could become infinite.
        i++;
    }
    
    // Return 0 to indicate the program ended successfully
    // Returning 0 is a standard way to indicate that the program executed without errors.
    return 0;
}