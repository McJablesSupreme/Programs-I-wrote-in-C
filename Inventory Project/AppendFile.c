//  PROJECT #6 File Append Program //

/* AppendFile.c by Justin Becker

Input:   Keyboard
Output:  Screen and Becker.txt disk file

This is a program that will append the Becker.txt file created in the CreateFile.c program.
A data structure is used to store the record information input by the user.
User input is collected using scanf and fgets, and then written to the disk file using fprintf. 
Prompts are displayed on screen using printf.
The program will prompt the user to enter data for each record in the file.
It will then write the data to the disk file.
After each completed entry, the user will be prompted to enter another record or to exit the program.
The program will continue to prompt the user to enter another record until the user enters 'N' or 'n' to exit the program, upon which it will close the disk file and exit.
*/

// =====================================================================================================================================
// INCLUDE STATEMENTS
#include <Windows.h> 
#include <stdio.h>
#include <stdlib.h>

// =====================================================================================================================================
// STRUCTURE DEFINITION
struct gearTemplate 
{
  int recordNumber; 
  int yearAcquired;
  float gearCost;
  char gearType[26], gearBrand[26], gearModel[26];
};

// =====================================================================================================================================
// MAIN FUNCTION
int main(void )
  {
// =================================================================================================
// Structure declaration
  struct gearTemplate gear; // Declare a structure variable

  // variable used to control loop, will not be in the disk file
  char again = 'Y';

  // variables used to play a melody
  int num_notes = 5;             // Number of notes in the melody
  int notesup[] = {370, 450, 560, 640, 780}; // Array of ascending notes
  int notesdown[] = {780, 640, 560, 450, 370}; // Array of descending notes
  int duration = 50;            // Duration of each note

  FILE *data_file;          // file pointer
// =================================================================================================
// Clear the screen 
  system("cls"); // clears the screen 

// Alert user that they are about to add new entries to the inventory file and ask if they want to continue
  printf("\nYou are about to add new entries to the Gear Inventory file.\a\a\a"); 
  printf("\nWould you like to continue? (Y/N): ");
  scanf(" %c", &again);

  while (again != 'Y' && again != 'y' && again != 'N' && again != 'n') // validate input
  {
    printf("\nInvalid input. Please enter Y or N: \a\a\a"); 
    scanf(" %c", &again);
  }
  if (again == 'N' || again == 'n') // if user does not want to continue, exit program
  {
    for (int n = 0; n < num_notes; n++) // play a melody
    {
        Beep(notesdown[n], duration);
    }
    printf("Returning to Main Menu"); // elipsis are printed on a delay to give the user time to read the message
    Sleep(400); 
    printf(".");
    Sleep(400);
    printf(".");
    Sleep(400);
    printf(".");
    Sleep(400);
    exit(1);
  }

// =================================================================================================
// OPEN FILE IN APPEND MODE   
  // attempt to open file in "append" mode and assign it to the file pointer
  if ((data_file = fopen("Becker.txt","a")) == NULL) 
  {
	printf("File location could not be opened for appending, program will exit\a\a\a\n");
	exit(1); // program ends here if file pointer returns NULL due to unknown abnormal condition
  }
// =================================================================================================
// PROCESSING
  // proceed if the file was opened properly for appending
// =================================================================================================
// HEADING
  printf("\n\t\t\t\t\t\tAdd New Records to Gear Inventory\n"); // Program heading
  for (int n = 0; n < num_notes; n++) // play a melody
  {
    Beep(notesup[n], duration);
  }
  printf("********************************************************************************************************************\n\n");
  // =================================================================================================
  // LOOP
  // start loop
  while (again == 'Y' || again == 'y') // loop will continue until user enters 'N' or 'n'
  {
    // ============================================================================================
    // GATHER KEYBOARD INPUTS
    // enter the record number and clear the keyboard buffer
    printf("Enter Record Number:\t\t");       // prompt user for record number
    scanf("%d", &gear.recordNumber);          // enter an int value
	while (getchar() != '\n');  // this loop calls getchar() will read "leftover" data       
	     // from the input stream, basically discarding them
		 // necessary because we must "clear" out the input stream whenever we
        //  transition from using scanf to fgets

    // enter string data 
    printf("Enter Gear Type:\t\t");   // prompt user for gear type
    fgets(gear.gearType,26,stdin); // incorporating c's file-get-string to gather string input 
	    // from keyboard so that a line feed IS included to properly terminate the 
		// string, which allows it to be properly read in the "read" application and
        // also because scanf will fail if any white space is encountered 

	  printf("Enter Gear Brand:\t\t");  // prompt user for gear brand
	  fgets(gear.gearBrand,26,stdin); // enter a string value

    printf("Enter Gear Model:\t\t"); // prompt user for gear model
    fgets(gear.gearModel, 26, stdin); // enter a string value

    // enter a float value and clear the keyboard buffer
	  printf("Enter Gear Cost:\t\t"); // prompt user for gear cost
    scanf("%f", &gear.gearCost);    // enter a float value

    // enter an int value
	  printf("Enter Acquisition Year:\t\t");  // prompt user for year acquired
    scanf("%d", &gear.yearAcquired);        // enter an int value

  // =================================================================================================
	// WRITE TO DISK
	// write the data to the file using fprintf for numerics and fputs for strings - CHANGE accordingly
  fprintf(data_file, "%d\n", gear.recordNumber); // although the \n is not required it makes for a cleaner appearance
  fputs(gear.gearType, data_file);               // puts the string out to the file, with a line feed included
  fputs(gear.gearBrand, data_file);              // puts the string out to the file, with a line feed included
  fputs(gear.gearModel, data_file);              // puts the string out to the file, with a line feed included
  fprintf(data_file, "%f\n", gear.gearCost);  // although the \n is not required it makes for a cleaner appearance
  fprintf(data_file, "%d\n", gear.yearAcquired); // note the newline after the last variable to separate records

  // note that the six lines above could be written into one fprintf statement as shown here, however 
	// your program should use fprintf and fputs to practice with those techniques
	// fprintf(data_file, "%d\n%s%s%f\n%d\n", recordNumber, string, string2, y, z);
    // =================================================================================================
    // Determine if user wants to enter another record
  printf("Do you want to enter another record? (Y/N): "); // ask user if they have more data to enter
  scanf(" %c", &again);
  while (again != 'Y' && again != 'y' && again != 'N' && again != 'n') // validate input
  {
    printf("\nInvalid input. Please enter Y or N: \a\a\a");
    scanf(" %c", &again); 
   }
   if (again == 'N' || again == 'n')
   {
    for (int n = 0; n < num_notes; n++)
    {
        Beep(notesdown[n], duration);
    }
     printf("Returning to Main Menu"); // elipsis are printed on a delay to give the user time to read the message
     Sleep(400);
     printf(".");
     Sleep(400);
     printf(".");
     Sleep(400);
     printf(".");
     Sleep(400);
     exit(1);
   }  
  } // end loop
// =================================================================================================
// CLOSE FILE 
  fclose(data_file); // close the file
// =================================================================================================
// TERMINATE PROGRAM
  return 0; 
  }
  