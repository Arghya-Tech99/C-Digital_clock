#include<stdio.h>
#include<time.h>
#include<string.h>

void getTime(char*, int);
int format_Choice(); 
void fillDate(char*);

int main() {

    int choice = format_Choice();
    char time[50];
    char date[100];

    getTime(time, choice);
    fillDate(date);
    printf("\n Current time : %s", time); // Prints the current local time
    printf("\n Date : %s", date); // Prints the date
    
    return 0;
}

void getTime(char* buffer, int format) {

    time_t rawTime; // declares a variable named rawTime of the data type time_t
    struct tm *currentTime; // Declaring a structure name 'tm' and a pointer to this structure with the name 'currentTime'
    time(&rawTime); // get the current calendar time and store that value in "rawTime" variable
    currentTime = localtime(&rawTime); // Converts time value stored in "rawTime" into a local time format and assigns to structure
    
    if (format == 1) {
    strftime(buffer, 50, "%H:%M:%S", currentTime); // Formats the time data type into a string variable; displays in 24 hour fomrat
    } else {
    strftime(buffer, 50, "%I:%M:%S %p", currentTime); // Formats the time data type into a string variable; displays 12 hour fomrat
    }
}

int format_Choice() {
    int format;
    printf("Please enter the format in which you want the time to be displayed");
    printf("\n 1. 24 hour format");
    printf("\n 2. 12 hour format (Default)");
    printf("\n Enter your choice(1/2): ");
    scanf("%d", &format);

    return format;
}

void fillDate(char* buffer) {
    time_t rawTime; // declares a variable named rawTime of the data type time_t
    struct tm *currentTime; // Declaring a structure name 'tm' and a pointer to this structure with the name 'currentTime'
    time(&rawTime); // get the current calendar time and store that value in "rawTime" variable
    currentTime = localtime(&rawTime); // Converts time value stored in "rawTime" into a local time format and assigns to structure

    strftime(buffer, 100, "%A %B %d %Y", currentTime); // Formats the local time format into into string variable and displays date 
}