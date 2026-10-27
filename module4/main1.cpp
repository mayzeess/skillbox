#include <iostream>
using namespace std;

int main(){
    cout << "Программа для поиска минимального числа.\n";
    int number1;
    int number2;
    cout << "Введите первое число: ";
    cin >> number1;
    cout << "Введите второе число: ";
    cin >> number2;
    cout << "-----Проверяем-----\n";

    if (number1 < number2) {
        cout << "Наименьшее число: " << number1;
    } else if (number1 == number2){
        cout << "Числа равны!";
    } else {
        cout << "Наименьшее число: " << number2;
    }
    return 0;
}