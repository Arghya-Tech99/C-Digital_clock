#include<stdio.h>
#include<time.h>

void getTime(char*);

int main() {
    
    char time[30];
    getTime(time);

    printf("Current time : %s", time); // Prints the current local time
    return 0;
}

void getTime(char* buffer) {
    time_t rawTime; // declares a variable named rawTime of the data type time_t
    struct tm *currentTime; // Declaring a structure name 'tm' and a pointer to this structure with the name 'currentTime'
    
    // char buffer[30];

    time(&rawTime); // get the current calendar time and store that value in "rawTime" variable
    currentTime = localtime(&rawTime); // Converts time value stored in "rawTime" into a local time format and assigns to structure
    strftime(buffer, 30, "%I: %M: %S %p", currentTime); // Formats the time data type into a string variable; displays in HH:MM:SS fomrat

}