/* *******************************************************************************************
 * exmplSaveAs.c - <description>
 *
 * Compile instructions:
 * gcc/clang exmplSaveAs.c -o exmplSaveAs
 * pmake exmplSaveAs.makefile
 * -------------------------------------------------------------------------------------------
 * Author:  Patrik Eigenmann
 * eMail:   p.eigenmann@gmx.net
 * GitHub:  www.github.com/PatrikEigenmann/cpp
 * -------------------------------------------------------------------------------------------
 * Fri 2025-03-21 File created.                                                 Version: 00.01
 * -------------------------------------------------------------------------------------------
 * To Do's:
 * ********************************************************************************************/
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

void save_as_dialog();

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
    initscr();            // Start ncurses mode
    cbreak();             // Disable line buffering
    noecho();             // Disable echoing of typed characters
    keypad(stdscr, TRUE); // Enable special keys

    mvprintw(5, 5, "Press 's' to open the 'Save As' dialog.");
    mvprintw(6, 5, "Press 'q' to quit.");
    refresh();

    int ch;
    while ((ch = getch()) != 'q') { // Press 'q' to quit
        if (ch == 's') {
            save_as_dialog();       // Open the Save As dialog
        }
    }

    endwin(); // End ncurses mode
    return 0;
}

void save_as_dialog() {
    int width = 40, height = 10;
    int start_y = (LINES - height) / 2; // Center the dialog vertically
    int start_x = (COLS - width) / 2;   // Center the dialog horizontally

    WINDOW *dialog = newwin(height, width, start_y, start_x);
    box(dialog, 0, 0); // Draw a box around the window
    mvwprintw(dialog, 1, 2, "Save As"); // Title
    mvwprintw(dialog, 3, 2, "File Name: ");

    char filename[256] = "";
    echo(); // Allow typed characters to be visible
    mvwgetnstr(dialog, 3, 13, filename, 255); // Input file name
    noecho();

    // Simulate saving
    mvwprintw(dialog, 5, 2, "Saving as: %s", filename);
    wrefresh(dialog);
    getch(); // Wait for user to see the message

    delwin(dialog); // Delete the dialog window
}