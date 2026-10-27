#include <iostream>
using namespace std;

int main(){
    string startTime, endTime;
    cout << "Input format (HH:MM)\n";
    cout << "Input start time: ";
    cin >> startTime;
    cout << "Input end time: ";
    cin >> endTime;

    int hoursStart = ((startTime[0] - '0') * 10 + (startTime[1] - '0'));
    int hoursEnd = ((endTime[0] - '0') * 10 + (endTime[1] - '0'));

    int minutesStart = ((startTime[3] - '0') * 10 + (startTime[4] - '0'));
    int minutesEnd = ((endTime[3] - '0') * 10 + (endTime[4] - '0'));

    while(hoursStart < 0 || hoursStart > 23 || minutesStart < 0 || minutesStart > 59 || startTime[2] != ':' || endTime[2] != ':'){
        cout << "Try again. Input format (HH:MM)\n";
        cout << "Input start time: ";
        cin >> startTime;
        cout << "Input end time: ";
        cin >> endTime;
    }

    int hoursRoute = hoursEnd > hoursStart || minutesEnd > minutesStart && hoursEnd == hoursStart ? hoursEnd - hoursStart : hoursEnd + 24 - hoursStart;
    int minutesRoute = minutesEnd >= minutesStart ? minutesEnd - minutesStart : minutesEnd + 60 - minutesStart;

    hoursRoute = minutesEnd < minutesStart ? hoursRoute -= 1 : hoursRoute;

    cout << "The trip will take " << hoursRoute << " hours " << minutesRoute << " minutes";
    return 0;
}