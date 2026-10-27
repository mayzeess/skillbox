#include <iostream>
using namespace std;

int main(){
    int money;
    cout << "Ввдете сумму для снятия: ";
    cin >> money;
    if (money > 150'000 || money <= 0 || money % 100 != 0){
        cout << "Такую сумму снять нельзя";
        return 0;
    }

    cout << "Выдано: \n";
    if (money >= 5'000){
        cout << money / 5'000 << " купюр по 5 000\n";
        money %= 5'000;
    } if (money >= 2'000){
        cout << money / 2'000 << " купюр по 2 000\n";
        money %= 2'000;
    } if (money >= 1'000){
        cout << money / 1'000 << " купюр по 1 000\n";
        money %= 1'000;
    } if (money >= 500){
        cout << money / 500 << " купюр по 500\n";
        money %= 500;
    } if (money >= 200){
        cout << money / 200 << " купюр по 200\n";
        money %= 200;
    } if (money >= 100){
        cout << money / 100 << " купюр по 100\n";
        money %= 100;
    }

    return 0;
}