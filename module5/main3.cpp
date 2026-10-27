#include <iostream>
using namespace std;

int main(){
    int day, dayStart;
    cout << "Введите в какой день недели начинается месяц\n";
    cout << "(1-7) где 1 - понедельник, а 7 - воскресенье\n";
    cin >> dayStart;
    if (dayStart <= 0 || dayStart > 7) {
        cout << "С такого дня начало быть не может";
        return 0;
    }
    cout << "Введите день мая: ";
    cin >> day;
    if (day <= 0 || day > 31) {
        cout << "Такого дня быть не может";
        return 0;
    }
    int saturday = 7 - dayStart;
    int sunday = saturday + 1;
    if (day >= 1 && day <= 5 || day >= 8 && day <= 10){
        cout << "В этот день выходной, праздник";
    } else if (day == saturday || (day - saturday) % 7 == 0){
        cout << "В этот день выходной - Суббота";
    } else if (day == sunday || (day - sunday) % 7 == 0) {
        cout << "В этот день выходной - Воскресенье";
    } else {
        cout << "Этот день рабочий";
    }
    return 0;
}