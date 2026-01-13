
#include <stdio.h> // Default library needed for most C files
#include <time.h> // Handles and manipulates time data
#include <stdbool.h> // Lets the program handle true/false data
#include <windows.h> // Allows interaction with Windows OS

int main() {

    time_t rawtime = 0; // Stores time as an integer
    struct tm *pTime = NULL; // Creates a pointer to tm struct
    bool isRunning = true; // Creates a true var

    printf("DIGITAL CLOCK\n"); // Needs a title of course, to make it look good

    // The program runs as a continual true loop
    while(isRunning) {
        
        time(&rawtime); // Gets the system time and stores it as rawtime
        pTime = localtime(&rawtime); // Converts rawtime to local time
        
        // Time is displayd in the format: hour : min : sec
        printf("\r%02d:%02d:%02d",
            // pTime utilizes pointer operators to the three different time units
            pTime->tm_hour, 
            pTime->tm_min, 
            pTime->tm_sec);
        
        fflush(stdout); // Ensures quick output
        Sleep(1000); // Miliseconds is used, so 1000 = 1 sec
    }

    return 0; // 0 ensures a success, non-zero means failure
}