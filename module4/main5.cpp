#include <iostream>
using namespace std;

int main(){
    cout << "Кратность числа\n";
    int dividend;
    int divisor;
    cout << "Введите делимое число: ";
    cin >> dividend;
    cout << "Введите делитель: ";
    cin >> divisor;
    cout << "-----Проверяем-----\n";
    if (dividend % divisor == 0){
        cout << "Да, " << dividend << " делится на " << divisor << " без остатка!";
    } else {
        cout << "Нет, " << dividend << " не делится на " << divisor << " без остатка!";
    }
    return 0;
}