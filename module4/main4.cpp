#include <iostream>
using namespace std;

int main(){
    cout << "Калькулятор опыта\n";
    int experience;
    cout << "Введите число очков опыта: ";
    cin >> experience;
    cout << "-----Считаем-----\n";
    
    if (0 <= experience && experience < 1000) {
        cout << "Ваш уровень 1";
    } else if (1000 <= experience && experience < 2500) {
        cout << "Ваш уровень 2";
    } else if (experience >= 2500 && experience < 5000){
        cout << "Ваш уровень 3";
    } else if (experience >= 5000){
        cout << "Ваш уровень 4";
    } else {
        cout << "Ошибка, у персонажа может быть минимум 0 опыта";
    }
    return 0;
}