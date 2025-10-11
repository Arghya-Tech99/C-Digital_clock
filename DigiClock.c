#include<stdio.h>
#include<time.h>

int main() {
    time_t rawTime; // declares a variable named rawTime of the data type time_t
    struct tm *currentTime; // Declaring a structure name 'tm' and a pointer to this structure with the name 'currentTime'
    
    char buffer[30];

    time(&rawTime); // get the current calendar time and store that value in "rawTime" variable
    currentTime = localtime(&rawTime); // Converts time value stored in "rawTime" into a local time format and assigns to structure
    strftime(buffer, sizeof(buffer), "%H: %M: %S", currentTime); // Formats the time data type into a string variable

    printf("Cureent time : %s", buffer); // Prints the current local time
    return 0;
}