#include <iostream>
using namespace std;

int main(){
    int day;
    cout << "Введите день мая: ";
    cin >> day;
    if (day <= 0 || day > 31) {
        cout << "Такого дня быть не может";
        return 0;
    }
    if (day % 6 == 0 || day % 7 == 0 || (day >= 1 && day <= 5) || (day >= 8 && day <= 10)){
        cout << "В этот день выходной";
    } else {
        cout << "Этот день рабочий";
    }
    return 0;
}