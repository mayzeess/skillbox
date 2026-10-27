#include <iostream>
using namespace std;

int main(){
    int length, countSign;
    cout << "Введите общую длину контитула: ";
    cin >> length;
    cout << "Вводите количество восклицательных знаков: ";
    cin >> countSign;

    for (int x = 0; x < length; x++){
        if (x < (length - countSign) / 2) {cout << "~";}
        else if (countSign != 0) {cout << "!"; countSign--;}
        else {cout << "~";}
    }
    return 0;
}