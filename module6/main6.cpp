#include <iostream>
using namespace std;

int main(){
    cout << "Вклады\n";
    int money;
    int rate;
    int needMoney;
    int year = 0;
    cout << "Введите размер вклада: ";
    cin >> money;
    cout << "Введите процентную ставку: ";
    cin >> rate;
    cout << "Введите желаемую сумму: ";
    cin >> needMoney;
    while (needMoney > money){
        money += money * rate / 100;
        year++;
    }

    cout << "Придётся подождать: " << year << " лет";

    return 0;
}