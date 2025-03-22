/* *******************************************************************************************
 * exmplNCurses.c - <description>
 *
 * Compile instructions:
 * gcc/clang exmplNCurses.c -o exmplNCurses
 * pmake exmplNCurses.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Fri 2025-03-21 File created.                                                 Version: 00.01
 * -------------------------------------------------------------------------------------------
 * To Do's:
 * ********************************************************************************************/
#include<stdio.h>
#include <ncurses.h> // Include the ncurses library

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
    // Initialize ncurses
    initscr();            // Start the ncurses mode
    cbreak();             // Disable line buffering
    keypad(stdscr, TRUE); // Enable special keys capture
    noecho();             // Do not echo typed characters

    // Create and position text
    mvprintw(5, 10, "Hello, ncurses!"); // Display text at (y=5, x=10)
    mvprintw(7, 10, "Press any key to move this text around.");

    refresh(); // Update the screen to display changes

    int ch;
    int y = 5, x = 10;

    // Interactive loop: Allow user to move text
    while ((ch = getch()) != 'q') { // Press 'q' to quit
        clear(); // Clear the screen

        switch (ch) {
            case KEY_UP:    y--; break;
            case KEY_DOWN:  y++; break;
            case KEY_LEFT:  x--; break;
            case KEY_RIGHT: x++; break;
        }

        mvprintw(y, x, "Move me with arrow keys!"); // Reposition text
        mvprintw(20, 0, "Press 'q' to quit.");
        refresh();
    }

    // End ncurses
    endwin();
    return 0;
}