#include <iostream>
using namespace std;

void restaurant(){
    int minutesChange;
    int orderTimeMinutes;
    int assemblingOrder;
    cout << "Эта программа рсчитает, сколько клиетов успеет обслужить кассир за смену.\n" ;
    cout << "Введите длительность смены: ";
    cin >> minutesChange;
    cout << "Ввдите, сколько минут клиет делает заказ: ";
    cin >> orderTimeMinutes;
    cout << "Введите сколько минут кассир собирает заказ: ";
    cin >> assemblingOrder;
    cout << "----Считаем----\n";
    int result = minutesChange / (orderTimeMinutes + assemblingOrder);
    cout << "Кассир за смену в " << minutesChange << " минут успеет обслужить " << result << " клиетов.";
}

int main() {
    restaurant();
    return 0;
}