// PROJECT #6 File Read Program //

/* ReadFile.c by Justin Becker
   Input:   Keyboard and Becker.txt file
   Output:  Screen

  This program reads multiple data types and strings that were written to a text file by the "CreateFile.c" program.
  File input comes from the "Becker.txt" data file, and the data is displayed on the screen.
  The user will be prompted to press any key to return to the main menu after the data is displayed using the getch() function.
  The "fixgets.h" header file is used to fix the fgets() function, which is used to read strings from the text file.
  The "fixgets.h" header file was written by Harry Brown, and is included in the project folder.
  Date and time are also displayed on the report using the <ctime> header and the ctime() function.
  The "get_current_year()" function is used to get the current year from the system and calculate the number of years a gear item has been owned.
  The "totalCost" and "noOfRecords" variables are used to calculate the average cost of all gear items.
*/

#include <Windows.h> 
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>  
#include <conio.h>   
#include <iomanip>
#include "fixgets.h" // Harry Brown's fixgets will be utilized

using namespace std;

// Structure definition
struct gearTemplate
{
  int recordNumber;
  int yearAcquired;
  float gearCost;
  char gearType[26], gearBrand[26], gearModel[26];
};

// Function prototypes
int get_current_year(void); // Get the current year

// Global variable 
float totalCost = 0.0f; // used to calculate the total cost of all gear
int noOfRecords = 0; // used to calculate the number of records

int main(void)
{
  system("cls"); // clears the screen
  
  // Variable declarations
  int yearsOwned = 0; // used to calculate the number of years owned
  int currentYear = 0; // used to store the current year

  //Structure variable
  gearTemplate gear;

  //====================================================================================
  // DATE/TIME variables for report stamp
  time_t now = time(NULL); // get the current time and date from the system
  char *timestamp = ctime(&now); // create a string pointer to the time and date

  // variables used to play a melody
  int num_notes = 5;                           // Number of notes in the melody
  int notesup[] = {370, 450, 560, 640, 780};   // Array of ascending notes
  int notesdown[] = {780, 640, 560, 450, 370}; // Array of descending notes
  int duration = 50;                           // Duration of each note

  //====================================================================================
  FILE *data_file; // file pointer
                   //==================================================================================
                   // OPEN FILE IN READ MODE
  // attempt to open file in "read" mode and assign it to the file pointer
  if ((data_file = fopen("Becker.txt", "r")) == NULL)
  {
    cout << "File not found, program will exit" << endl;
    exit(1);
  }
  //==================================================================================
  // PROCESSING
  // proceed if the file was opened successfully
  //==================================================================================
  // HEADINGS
  cout << endl << endl << "\t\t\t\t\t\t\tGear Inventory Report" << endl; // print report title
      cout
       << "***********************************************************************************************************************************" << endl
       << endl;

      for (int n = 0; n < num_notes; n++) // play a melody
    {
        Beep(notesup[n], duration); 
    }

      Sleep(200);
      // print date and time report was generated
      cout << "\t\t\t\t\t\tReport Date: " << timestamp << endl;
      Sleep(200);
      // column headings
      cout << left << setw(20) << "RECORD NUMBER";
      Sleep(200);
      cout << setw(20) << "GEAR TYPE";
      Sleep(200);
      cout << setw(20) << "BRAND";
      Sleep(200);
      cout << setw(25) << "MODEL";
      Sleep(200);
      cout << right << setw(11) << "COST";
      Sleep(200);
      cout << right << setw(20) << "YEAR ACQUIRED";
      Sleep(200);
      cout << right << setw(15) << "YEARS OWNED";
      Sleep(200);
      cout << endl;
      //==================================================================================
      // PRIMING READ
      // following six lines are the "priming" read of the data items in the first record
      fscanf(data_file, "%d\n", &gear.recordNumber); // read the integer note that \n is included to read and discard the
                                                // newline character from the data file so that fixgets does not
                                                // think it is the string
      fixgets(gear.gearType, 26, data_file);    // using fixgets function to retrieve the string
                                                // and strip out its line feed so that we can place other
                                                // items on the same line and because fscanf will fail to
                                                // read past the first white space
      fixgets(gear.gearBrand, 26, data_file);   // using fixgets function to retrieve the string
                                                // and strip out its line feed so that we can place other
                                                // items on the same line and because fscanf will fail to
                                                // read past the first white space
      fixgets(gear.gearModel, 26, data_file);   // read the next string
      fscanf(data_file, "%f", &gear.gearCost);  // read the float
      fscanf(data_file, "%d", &gear.yearAcquired); // read the integer
                                                   //==================================================================================
                                                   // LOOP
      while (!feof(data_file))                  // loop until end of file is reached
      {
    /*******************************************/
    // Calculations 
    noOfRecords++; // increment the number of records
    totalCost += gear.gearCost; // add the cost of the gear to the total cost

    // calculates the number of years owned by subtracting the year acquired from the current year
    currentYear = get_current_year();

    yearsOwned = currentYear - gear.yearAcquired;
    // print a row of data

    //printf("\t%8d  \t%-20s    %-20s\t\t  %-20s\t\t   %8.2f   \t\t%8d\n", recordNumber, gearType, gearBrand, gearModel, gearCost, yearAcquired);
    //cout << "\t" << recordNumber << "\t\t" << gearType << "\t\t" << gearBrand << "\t" << gearModel << "\t" << gearCost << "\t" << yearAcquired << endl;
    //cout << setw(15) << left << recordNumber << setw(10) << gearType << setw(15) << left << gearBrand << setw(10) << left << gearModel << setw(10) << left << gearCost << setw(10) << left << yearAcquired << endl;
    cout << right << setw(5) << gear.recordNumber
         << setw(15) << " "
         << left << setw(20) << gear.gearType
         << setw(20) << gear.gearBrand
         << setw(25) << gear.gearModel
         << "  $"
         << right << setw(8) << setprecision(2) << fixed << gear.gearCost
         << right << setw(15) << gear.yearAcquired
         << right << setw(15) << yearsOwned 
         << endl;
    Sleep(200); // pauses after printing each record so they don't all appear on screen at once
    // read the next record
    fscanf(data_file, "%d\n", &gear.recordNumber); // read the integer, discard the \n
    fixgets(gear.gearType, 26, data_file);         // using fixgets function to retrieve the string
                                                   // and strip out its line feed so that we can place other
                                                   // items on the same line and because fscanf will fail to
                                                   // read past the first white space
    fixgets(gear.gearBrand, 26, data_file);        // read the next string
    fixgets(gear.gearModel, 26, data_file);        // read the next string
    fscanf(data_file, "%f", &gear.gearCost);       // read the float
    fscanf(data_file, "%d", &gear.yearAcquired);   // read the integer
  }
  //==================================================================================
  // Print calculation results
  cout << endl << endl << "Total Cost of All Gear: $" << totalCost << endl; // print total cost
  Sleep(200);
  cout << "Number of Records in Report: " << noOfRecords << endl; // print number of records
  Sleep(200);
  cout << "Average Cost per Gear Item: $" << totalCost / noOfRecords << endl; // print average cost per item
  Sleep(200);

  //==================================================================================
  // CLOSE FILE
  fclose(data_file); // close the file
  
  //==================================================================================
  cout << endl << "\t\t\t\t\t\t\t    END OF REPORT";                   
  cout << endl << "***********************************************************************************************************************************";                 
  cout << endl << endl << "Press any key to return to the Main Menu" << endl;
  getch();          // pause the program until the user presses a key

  cout << "Returning to Main Menu"; // elipses are printed on a delay to give the user time to read the message
  for (int n = 0; n < num_notes; n++) // play a melody
  {
    Beep(notesdown[n], duration);
  }
  printf(".");
  Sleep(400);
  printf(".");
  Sleep(400);
  printf(".");
  Sleep(400);
  return 0;          // program ends and returns to main menu
}

//====================================================================================
// FUNCTION DEFINITIONS
//====================================================================================
// Gets the current year and returns it as an integer for use in calculations
int get_current_year()
{
  time_t now = time(NULL);            // get the current time
  struct tm *local = localtime(&now); // convert to local time
  return local->tm_year + 1900;       // return the year
}