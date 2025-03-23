/* *******************************************************************************************
 * exmplTab.c - <description>
 *
 * Compile instructions:
 * gcc/clang exmplTab.c -o exmplTab
 * pmake exmplTab.makefile
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

#include <ncurses.h>

// Function declarations for each tab
void show_input_tab();
void show_output_tab();
void show_help_tab();

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
    noecho();             // Disable echo
    keypad(stdscr, TRUE); // Enable special keys

    int choice = 0;       // Track current tab
    int ch;               // User input

    while (true) {
        clear();          // Clear the screen

        // Display tab header
        mvprintw(0, 0, "Use LEFT/RIGHT arrows to navigate tabs | Press 'q' to quit.");
        mvprintw(1, 0, "Tabs: [Input] [Output] [Help]");

        // Highlight the active tab
        if (choice == 0) attron(A_REVERSE);
        mvprintw(1, 7, "Input");
        attroff(A_REVERSE);

        if (choice == 1) attron(A_REVERSE);
        mvprintw(1, 15, "Output");
        attroff(A_REVERSE);

        if (choice == 2) attron(A_REVERSE);
        mvprintw(1, 24, "Help");
        attroff(A_REVERSE);

        // Call the respective function for the active tab
        switch (choice) {
            case 0: show_input_tab(); break;
            case 1: show_output_tab(); break;
            case 2: show_help_tab(); break;
        }

        refresh(); // Update the screen

        // Handle user input
        ch = getch();
        if (ch == KEY_RIGHT) {
            choice = (choice + 1) % 3; // Move to next tab
        } else if (ch == KEY_LEFT) {
            choice = (choice - 1 + 3) % 3; // Move to previous tab
        } else if (ch == 'q') {
            break; // Quit the program
        }
    }

    endwin(); // End ncurses mode
    return 0;
}

// Functions to show content for each tab
void show_input_tab() {
    mvprintw(3, 0, "This is the Input tab.");
    mvprintw(4, 0, "Type your data here...");
}

void show_output_tab() {
    mvprintw(3, 0, "This is the Output tab.");
    mvprintw(4, 0, "See the processed data here...");
}

void show_help_tab() {
    mvprintw(3, 0, "This is the Help tab.");
    mvprintw(4, 0, "Navigate using LEFT/RIGHT arrows.");
    mvprintw(5, 0, "Press 'q' to quit.");
}