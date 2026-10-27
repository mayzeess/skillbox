#include <iostream>
using namespace std;

int main(){
    cout << "Слишком большие числа\n";
    int number;
    cout << "Введите чиисло для подчета цифр: ";
    cin >> number;

    int count = 0;
    do {
        number /= 10;
        count++;
    } while(number != 0);

    cout << "Цифр в числе: " << count;
    return 0;
}