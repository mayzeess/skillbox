#include <iostream>
#define MONDAY 0
#define TUESDAY 1
#define WEDNESDAY 2
#define THURSDAY 3
#define FRIDAY 4
#define SARTURDAY 5
#define SUNDAY 6
using namespace std;

int main(){
    int day;
    cout << "Input number day: ";
    cin >> day;
    day %= 7;
    if (day == MONDAY){
        cout << "It is MONDAY now.\n";
    }
    else if (day == TUESDAY){
        cout << "It is TUESDAY now.\n";
    }
    else if (day == WEDNESDAY){
        cout << "It is WEDNESDAY now.\n";
    }
    else if (day == THURSDAY){
        cout << "It is THURSDAY now.\n";
    }
    else if (day == FRIDAY){
        cout << "It is FRIDAY now.\n";
    }
    else if (day == SARTURDAY){
        cout << "It is SARTURDAY now.\n";
    }
    else if (day == SUNDAY){
        cout << "It is SUNDAY now.\n";
    }
    return 0;
}