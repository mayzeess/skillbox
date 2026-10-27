#include <iostream>
using namespace std;

int main(){
    cout << "Счастливый билетик\n";
    
    int number;
    cout << "Введите номер билета: ";
    cin >> number;
    if (number < 0){
        cout << "Такой билет быть не может";\
        return 0;
    }

    int sum1 = 0, sum2 = 0, i = 0;
    // чтобы добавить билет длинее нужно поменять условие i < 3
    // где второе число = длина билета / 2. (6/2=3)
    while (number != 0){
        if (i < 3){
            sum1 += number % 10;
            i++;
        } else {
            sum2 += number % 10;
        }
        number /= 10;
    }

    if (sum1 == sum2){
        cout << "Билет счастливый!";
    } else {
        cout << "Повезёт в следующий раз!";
    }
    return 0;
}