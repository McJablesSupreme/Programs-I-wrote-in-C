//  PROJECT #6 RestoreFile Program //

/* RestoreFile.c by Justin Becker

Input:   Keyboard and BACKUPBecker.txt disk file
Output:  Screen and Becker.txt disk file

This is a program that will restore the inventory file from a backup file.
The program will prompt the user to confirm that they want to restore the file from the backup file before proceeding.
If the user confirms that they want to restore the file, the program will open the backup file and the inventory file.
It will then read the backup file and write the data to the inventory file.
The program will then close both files, alert the user that the process was successful, and exit.

*/

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{

    
    FILE *original_file, *backup_file; // file pointers
    char ch; // variable used to store characters read from the file
    char again = 'Y';

    // variables used to play a melody
    int num_notes = 5;                           // Number of notes in the melody
    int notesup[] = {370, 450, 560, 640, 780};   // Array of ascending notes
    int notesdown[] = {780, 640, 560, 450, 370}; // Array of descending notes
    int duration = 50;                           // Duration of each note

    system("cls"); // clears the screen
    printf("\nYou are about to restore the Inventory File from a backup file.\nIf you continue, the Inventory File will be overwritten.\a\a\a");
    printf("\nAre you sure you want to continue? (Y/N): ");
    scanf(" %c", &again);
    while (again != 'Y' && again != 'y' && again != 'N' && again != 'n') // validate input 
    {
        printf("Invalid input. Please enter Y or N: \a\a\a"); 
        scanf(" %c", &again);
    }
    if (again == 'N' || again == 'n') // if user does not want to continue, program will exit back to main menu
    {
        printf("\nFile was NOT restored from backup.\nPress any key to return to the Main Menu\n"); 
        getch();
        for (int n = 0; n < num_notes; n++)
        {
            Beep(notesdown[n], duration);
        }
        printf("Returning to Main Menu"); // elipses printed on a delay to give the user time to read the message
        Sleep(400);
        printf(".");
        Sleep(400);
        printf(".");
        Sleep(400);
        printf(".");
        Sleep(400);
        exit(1);
    }

    backup_file = fopen("BACKUPBecker.txt", "r"); // open backup file for reading
    original_file = fopen("Becker.txt", "w"); // open inventory file for writing
    if (original_file == NULL || backup_file == NULL) // if either file cannot be opened, program will exit
    {
        printf("Error: File not found.\a\a\a\n");
        printf("Press any key to return to the Main Menu\n");
        getch();
        for (int n = 0; n < num_notes; n++)
        {
            Beep(notesdown[n], duration);
        }
        printf("Returning to Main Menu");
        Sleep(400);
        printf(".");
        Sleep(400);
        printf(".");
        Sleep(400);
        printf(".");
        Sleep(400);
        exit(1);
    }
    while ((ch = fgetc(backup_file)) != EOF) // read backup file and write to inventory file
    {
        fputc(ch, original_file);
    }
    printf("\nFile was successfully restored from backup.\n");
    for (int n = 0; n < num_notes; n++)
    {
        Beep(notesup[n], duration);
    }
    fclose(original_file);
    fclose(backup_file);
    printf("Press any key to return to the Main Menu\n");
    getch();
    for (int n = 0; n < num_notes; n++)
    {
        Beep(notesdown[n], duration);
    }
    printf("Returning to Main Menu");
    Sleep(400);
    printf(".");
    Sleep(400);
    printf(".");
    Sleep(400);
    printf(".");
    Sleep(400);
    return 0;
}

