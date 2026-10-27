#include <iostream>
#include <string>
using namespace std;

int main(){
    int number; 
    cout << "Input number (1 - 3999): ";
    cin >> number;

    while (number < 1 || number > 3999){
        cout << "Try again.\nInput number (1 - 3999): ";
        cin >> number;
    }
    char numbers[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int indNumbers = 5;

    cout << string(number/1000, 'M');
    number -= (number/1000) * 1000;

    for (int i = 100; i > 0; i /= 10){
        int current = number / i;
        number -= current * i;
        while (current > 0) {
            if (current == 9){
                cout << numbers[indNumbers - 1] << numbers[indNumbers + 1];
                current -= 9;
            }
            else if (current == 4){
                cout << numbers[indNumbers - 1] << numbers[indNumbers];
                current -= 4;
            }
            else if (current >= 5){
                cout << numbers[indNumbers];
                current -= 5;
            }
            else {
                cout << numbers[indNumbers - 1];
                current -= 1;
            }
        }
        indNumbers -= 2; // в последней работе цикла, переменная индекса становится
        // отрицательной, это ошибка, такого быть не может. 
        // но все хорошо рабтает без ошибок, так как это просто переменная int, 
        // а к массиву я уже после этого не обращаюсь, так как это все равно последний
        // проход цикла. Всегда будет работать без ошибок. 
    }
    
    return 0;
}