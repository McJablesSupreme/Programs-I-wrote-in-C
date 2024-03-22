/***IMPORTANT NOTE***/
/***THIS PROGRAM WILL NOT COMPILE PROPERLY UNLESS YOU USE THE FOLLOWING COMPILER COMMAND***/
/* g++ -o gimMenu gimMenu.cpp -lwinmm */

//  PROJECT #6 Menu Program //

/* gimMenu.cpp by Justin Becker

Input:   Keyboard
Output:  Screen and Becker.txt disk file 

This is the main menu for the Gear Inventory Management program. 
It allows the user to create a text file, restore that text file from backup, or read from the text file. 
The user will select a choice using the keyboard, and the program will execute the appropriate function using the switch case statement.
When the program is initially run, a short welcome jingle I wrote and recorded will play.
Use of the "cls" command will clear the screen in between function calls and each time the main menu loads.
the "system" command is used to compile and execute the source code files for each function.
*/

// =====================================================================================================================================
// INCLUDE STATEMENTS
#include <Windows.h> 
#pragma comment (lib, "Winmm.lib") 
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>

// =====================================================================================================================================
// FUNCTION PROTOTYPES
void create_file(); // compiles and executes the program needed to create a text file
void read_file(); // compiles and executes the program needed to read from the text file
void restore_file(); // compiles and executes the program needed to restore the text file from backup
void append_file(); // compiles and executes the program needed to append data to the text file

// =====================================================================================================================================
// MAIN FUNCTION
int main()
{
    int choice; // variable to store the user's choice

    PlaySound("InventoryIntroJingle.wav", NULL, SND_FILENAME | SND_ASYNC); // play the intro jingle

    // ======================================================================
    // main menu
    do
    {
    system("cls"); // clears the screen each time the main menu loads
    printf("\t\t\t\t\t   Gear Inventory Main Menu\n");
    printf("********************************************************************************************************************\n\n");
    Sleep(100);
    printf("Please choose one of the following options:\n");
    Sleep(100);
    printf("1. Create Inventory File\n");
    Sleep(100);
    printf("2. Append Inventory File\n");
    Sleep(100);
    printf("3. Restore Inventory File From Backup\n");
    Sleep(100);
    printf("4. Generate Inventory Report\n");
    Sleep(100);
    printf("5. Exit Program\n");
    Sleep(100);
    scanf("%d", &choice); // collect the user's choice

    // ======================================================================
    // switch case statement to execute the user's choice
    switch (choice) // use switch case to execute selected option
    {
        case 1:
            create_file(); // call the create file function
            break;
        case 2:
            append_file(); // call the append file function
            break;
        case 3:
            restore_file(); // call the restore file function
            break;
        case 4:
            read_file(); // call the read file function
            break;
        case 5:
            printf("\nThank you for using the Gear Inventory program!\n"); // exit the program
            printf("Press any key to exit the program\n"); 
            getch(); // wait for the user to press a key
            return 0; // exit the program
        default:
            printf("Invalid choice!\n"); // display error message if the user enters an invalid choice
            break;
    }
    } while (choice != 5); // loop until the user chooses to exit

    //return 0; // exit the program
}

// =====================================================================================================================================
// FUNCTION DEFINITIONS

// ======================================================================
// function to create a text file using CreateFile.c
void create_file()
{
    system("gcc CreateFile.c -o CreateFile"); // compile the source code file
    system("CreateFile"); // run the executable file
}

// ======================================================================
// function to read from a text file using ReadFile.cpp
void read_file()
{
    system("g++ ReadFile.cpp -o ReadFile"); // compile the source code file
    system("ReadFile"); // run the executable file
}

// ======================================================================
// function to restore a text file from backup using RestoreFile.c
void restore_file()
{
    system("gcc RestoreFile.c -o RestoreFile"); // compile the source code file
    system("RestoreFile"); // run the executable file
}

// ======================================================================
// function to append data to a text file using AppendFile.c
void append_file()
{
    system("gcc AppendFile.c -o AppendFile"); // compile the source code file
    system("AppendFile"); // run the executable file
}