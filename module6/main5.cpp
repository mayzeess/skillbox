#include <iostream>
using namespace std;

int main(){
    cout << "Числа Фибоначчи\n";
    
    int number;
    cout << "Введите номер последовательности: ";
    cin >> number;
    if (number == 2 || number == 1){
        cout << "Число в последовательности: 1";
        return 0;
    }
    int sum1 = 1, sum2 = 1, result;
    bool flag = false;
    while (number != 2){
        if (number < 0){
            cout << "Введите номер последовательности (больше 0): ";
            cin >> number;
        }
        if (flag){
            result = sum1 + sum2;
            sum1 = result;
            flag = false;
        } else {
            result = sum1 + sum2;
            sum2 = result;
            flag = true;
        }
        number--;
    }
    cout << "Число в последовательности: " << result;
    return 0;
}