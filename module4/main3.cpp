#include <iostream>
using namespace std;

int main(){
    cout << "Проверка на чётное число\n";
    int number;
    cout << "Введите число: ";
    cin >> number;
    cout << "-----Проверяем-----\n";
    
    if (number % 2 == 0) {
        cout << "Число - " << number << " четное.";
    } else {
        cout << "Число - " << number << " нечетное.";
    }
    return 0;
}