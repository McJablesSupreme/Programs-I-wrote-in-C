#include <stdio.h>
#include <conio.h>
#include <direct.h>
#include <windows.h>
//#include <mmsystem.h>
//#pragma comment(lib, "winmm.lib")

/* 
**Michigan Weather Analyzer Application**

This program allows a user to input the high temperature for fourteen days, 
and then analyzes the data to determine the average high temperature for the period.
An array is used to store the data collected from the user via the scanf() function.
Input is collected using the keyboard, and output is displayed on the user's screen using printf(). 

Written by Justin Becker 03/21/2023 for CIS185
*/

/************************************************************************************************************************************/
//Function prototypes
void printHeader(void); //Prints welcome message
int* getTemp(void); //Gets temperature data from user
int sumTemps(int temps[], int n); //Sums temperature data
void printResults(float); //Prints results
float avgTemps(int); //Analyzes temperature data
void maxMin(int temps[], int n); //Finds max and min temps and prints them
void printThanks(void); //Prints exit message
void playIntroJingle(void); //Plays intro sound and prints welcome message
void playOutroJingle(void); //Plays exit sound 

/************************************************************************************************************************************/
//Global counters
int coldDays = 0, warmDays = 0, hotDays = 0;

/************************************************************************************************************************************/
//Main function
int main(void)
{
/*****************************************************************************/    
    //Variable declarations
    int n = 14; //Number of days
    float average = 0.0f, summary = 0.0f; //Variables to hold average temperature and sum of temperature array

/*****************************************************************************/   
    //Function calls

    //PlaySound(TEXT("MIWeatherAnalyzerIntroJingle.mp3"), NULL, SND_FILENAME | SND_ASYNC);

    playIntroJingle(); //Function call to play intro sound and print welcome message

    int *temps = getTemp(); //Function call to prompt user and get temperature data

    int total = sumTemps(temps, n); //Function call to sum temperatures 

    average = avgTemps(total); //Function call to calculate average temperatures

    printResults(average); //Function call to print results and analysis

    maxMin(temps, n); //Function call to determine and print max and min temps

    playOutroJingle(); //Function call to play exit sound

    return 0; //Ends program
}
/************************************************************************************************************************************/
//Function definitions

void printHeader(void) //Prints welcome message
{
    printf("Michigan Weather Analyzer Application by Justin Becker\n\n");

}
/*****************************************************************************/

int* getTemp(void) //Collects user input and assigns the values to an array
{
    static int temps[14]; //Array to hold the temperature data collected from the user

    //Array of string messages to print if the temperature is over 70 
    char *message[] = {"What a nice day to be outside!", "Hey, that's pretty warm!", "Ayo, gettin hot in here!",
                       "Man oh man, gettin kinda warm out!", "Wowza, what a nice, warm day to be alive!",
                       "Holy smokes look at that temperature! Scorcher, amirite?", "Make sure you crank that AC - looks like another hot one!",
                       "Crimetly! What a warm day on planet Earth!", "Are you for real? THAT many days have been over 70? What the devil.",
                       "Okay, I feel like you might just be messing with me now. You're telling me almost EVERY day has been over 70 so far?",
                       "I'm starting to suspect you're testing me. What do you want - for me to freak out or something?",
                       "Oh wow! What a cold day! Better bundle up! Pysch. Got you.", "Yeah, I'm not gonna act like temps over 70 are that big a deal anymore. Deal with it.",
                       "ARE YOU TRYING TO VEX ME?? BECAUSE I AM BECOMING VEXED. HOW HAS EVERY DAY THE PAST TWO WEEKS BEEN SO HOT??"};
    int s = 0; //Counter for message array

        printf("Enter the high temperature for 14 days below\n"); //Prompts user to enter temperature data

    for (int i = 0; i < 14; i++) //Loop to collect user input
    {
        do //Loop to collect and validate user input
        {
            printf("Day #%3d? ", i+1);
            scanf("%d", &temps[i]);

            if (temps[i] < 0 || temps[i] > 100) //Validates user input
            {
                printf("\a\a\a\aInvalid temperature. Enter a value between 0 and 100.\n"); //Prints error message if user input is out of range
            }

            if (temps[i] > 70 && temps[i] <= 100) //Determines whether to print a message
            {
                printf("%s\n", message[s]); //Prints message if user input is over 70
                s++;
            }

            if (temps[i] < 60) //Counts # of cold days
            {
                coldDays++;
            }
            else if (temps[i] >= 60 && temps[i] <= 79) //Counts # of warm days
            {
                warmDays++;
            }
            else if (temps[i] >= 80) //Counts # of hot days
            {
                hotDays++;
            }

        } while (temps[i] < 0 || temps[i] > 100); //Ends loop if user input is valid
    }

    return temps; //Returns array address to main function
}

/*****************************************************************************/

int sumTemps(int *temps, int n) //Sums temperature array
{
    int localTotal = 0; //Variable to hold the sum of the temperatures

    for (int i = 0; i < n; i++) //Loop to sum temperatures
    {
        localTotal += temps[i]; //Sums temperatures
    }

    return localTotal; //Returns sum to main function
}

/*****************************************************************************/

float avgTemps(int total) //Calculates average temperature
{
    float average; //Variable to hold the average temperature

    average = (float) total / 14.0f; //Calculates average temperature for the two week period

    return average; //Returns average to main function
}

/*****************************************************************************/

void printResults(float average) //Prints results and analysis
{
    printf("\n================================\n");
    printf("The number of cold days:  %3d\n", coldDays); //Prints # of cold days
    printf("The number of warm days:  %3d\n", warmDays); //Prints # of warm days
    printf("The number of hot days:   %3d\n\n", hotDays); //Prints # of hot days
    printf("The average high temperature: %.2f\370\n", average); //Prints average temperature

    //Prints analysis based on average temperature
    if (average < 50.0f) 
    {
        printf("These two weeks were basically cold\n"); 
    }   
    else 
        if (average < 60.0f) 
        {
            printf("These two weeks were chilly\n");
        }
        else
            if (average < 70.0f)
            {
                printf("These two weeks were decent for Michigan\n");
            }
            else
                if (average < 80.0f)
                {
                    printf("These two weeks were warm for Michigan\n");
                }
                else
                    if (average < 90.0f)
                    {
                        printf("These two weeks were very warm for Michigan");
                    }
                    else
                        {
                            printf("These two weeks were hot for Michigan");
                        }
}

/*****************************************************************************/

void maxMin(int temps[], int n) //A function that prints the lowest and highest temperatures in an array
{
    //Initialize min and max to the first element of the array
    int min = temps[0]; //Variable to hold the lowest temperature
    int max = temps[0]; //Variable to hold the highest temperature

    for (int i = 0; i < n; i++) //Loop through the array and update min and max accordingly
    {
        if (temps[i] > max) //If the current element is greater than max, update max
        {
            max = temps[i];
        }

        if (temps[i] < min) //If the current element is less than min, update min
        {
            min = temps[i];
        }
    }

    // Print the results
    printf("\nThe lowest temperature was %4d\370\n", min);
    printf("The highest temperature was %3d\370\n\n", max);
}

/*****************************************************************************/

void playIntroJingle(void) //Plays the intro music and prints welcome message
{

    int notes[] = {262, 294, 330, 262, 330, 494, 440, 523}; //Array of notes to play for the intro jingle. Each value is a frequency in hertz that corresponds to a note from the C major scale.
    int duration = 200; //Duration of each note in milliseconds
    int num_notes = 8; //Number of notes in the array
    char *words[] = {"Michigan ", "Weather ", "Analyzer ", "Application ", "by ", "Justin ", "Becker ", ":]\n\n"}; //Array of words to print while the music plays
    int num_words = sizeof(words) / sizeof(words[0]); //calculates the number of words in the array

    for (int n = 0; n < num_notes; n++) //Loop to play the notes and print the words
    {
        Beep(notes[n], duration); //Plays the note
        if (n < num_words) //Prints the word if there is one to print
        { 
            printf("%s", words[n]); 
        }
    }
}

/*****************************************************************************/ 

void playOutroJingle(void) //Plays the outro music and prints thank you message
{
    int notes[] = {523, 494, 440, 392, 440, 330, 294, 262}; //Array of notes to play in the outro jingle. Each value is a frequency in hertz that corresponds to a note from the C major scale.
    int duration = 200; //Duration of each note in milliseconds
    int num_notes = 8; //Number of notes in the array
    char *words[] = {"Thank ", "you ", "for ", "using ", "the ", "Michigan ", "Weather ", "Analyzer!\n\n"}; //Array of words that print one word per note as the outro jingle plays
    int num_words = sizeof(words) / sizeof(words[0]); //Calculates the number of words in the array

    for (int n = 0; n < num_notes; n++) //Loop to play the notes and print the words
    {
        Beep(notes[n], duration); //Plays the note
        if (n < num_words) //Prints the word if there is a word to print
        {
            printf("%s", words[n]); 
        }
    }

    printf("Press any key to exit the program\n"); 
    getch();
}
