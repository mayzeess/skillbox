#include <iostream>
using namespace std;

int main(){
    cout << "Коллекторы\n";
    string name;
    int duty;
    cout << "Введите имя должника: ";
    cin >> name;
    cout << "Введите долг " << name << ": ";
    cin >> duty;

    while (duty > 0){
        int money;
        cout << "Введите взнос для погашения: ";
        cin >> money;
        if (money <= 0){
            cout << "Сумма взноса должна быть больше 0\n";
            continue;
        }
        duty -= money;
        cout << "Часть погашена, осталось " << duty << "\n";
    }
    if (duty < 0) {
        cout << "Долг погашен, остаток на счету: " << duty * -1;
    } else {
        cout << "Отлично, долг ровно погашен";
    }
    return 0;
}