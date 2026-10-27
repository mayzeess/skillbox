#include <iostream>
using namespace std;

int main(){
    cout << "Складываем в уме\n";
    int number1;
    int number2;
    int sum;
    cout << "Введите первое число: ";
    cin >> number1;
    cout << "Введите второе число: ";
    cin >> number2;
    cout << "Введите сумму чисел: ";
    cin >> sum;
    cout << "-----Проверяем-----\n";
    
    if (number1 + number2 == sum) {
        cout << "Верно!";
    } else {
        cout << "Ошибка! Верный результат: " << number1 + number2;
    }
    return 0;
}