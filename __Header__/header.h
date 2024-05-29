#include <iostream>
#include <ctime>
using namespace std;

string getDateTime()
{
    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);
    char timeBuffer[20];

    strftime(timeBuffer, sizeof(timeBuffer), "%d/%m/%Y || %H:%M", localTime);
    return string(timeBuffer);
}