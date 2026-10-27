#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main(){
    cout << "Input MM:SS: ";
    time_t time_now = time(nullptr);
    tm locale = *localtime(&time_now);

    cin >> get_time(&locale, "%M:%S");
    time_t time_end = time_now + locale.tm_min * 60 + locale.tm_sec;

    cout << "Timer start: " << put_time(&locale, "%M:%S") << endl;
    while (time_end >= time_now){
        time_t temp = time_end - time_now;
        while (temp == time_end - time_now){
            time_now = time(nullptr);
        }
        if (locale.tm_sec > 0){
            locale.tm_sec--;
        }
        else {
            locale.tm_min--;
            locale.tm_sec = 59;
        }
        
        cout << put_time(&locale, "%M:%S") << endl;
    }

    cout << "DING! DING! DING!" << endl;

    return 0;
}