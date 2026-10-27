#include <iostream>
using namespace std;

int main(){
    cout << "Программа подсчета налога\n";
    int money;
    cout << "Введите сумму для подсчета налога: ";
    cin >> money;

    if (money <= 10'000){
        cout << "Налог составит: " << money * 0.13;
    } else if (money <= 50'000){
        cout << "Налог составит: " << (money - 10'000) * 0.2 + 0.13 * 10'000;
    } else {
        cout << "Налог составит: " << ((money - 50'000) * 0.3) + ((50'000 - 10'000) * 0.2) + 10'000 * 0.13;
    } 

    return 0;
}