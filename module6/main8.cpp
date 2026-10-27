#include <iostream>
using namespace std;

int main(){
    cout << "Угадай число\n";
    cout << "Отвечайть можно только да/нет\n";
    int minNumber = 0, maxNumber = 63;
    //чтобы поменять диапазон, нужно изменить переменные minNumber и maxNumber
    int x = 0;
    bool numberGive = false;

    do{
        if (!numberGive){
            cout << "Загадайте число от " << minNumber << " до " << maxNumber << ": ";
            cin >> x;
            if (x < minNumber || x > maxNumber){
                cout << "Такое число загадать нельзя, только от 0 до 63.\n";
                continue;
            }
            numberGive = true;
        }
        int mid = minNumber + (maxNumber - minNumber) / 2;
        string answer;
        cout << "Ваше число больше " << mid << "?\n";
        cin >> answer;
        if (answer != "да" && answer != "нет"){
            cout << "Отвечать можно только да/нет\n";
            continue;
        } else if (answer == "да"){
            minNumber = mid + 1;
        } else {
            maxNumber = mid;
        }

    } while(minNumber < maxNumber);

    cout << "Ваше число: " << minNumber;
    return 0;
}