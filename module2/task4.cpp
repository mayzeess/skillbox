#include <iostream>
using namespace std;

void housingCosts(){
    int price;
    int entrance;
    int apartment;
    cout << "Приветствуем вам в калькуляторе квартплаты!\n\n";
    cout << "Введите сумму, указанную в квитанции: ";
    cin >> price;
    cout << "Сколько у вас подъездов? ";
    cin >> entrance;
    cout << "Сколько квартир в каждом подъезде? ";
    cin >> apartment;
    cout << "----Считаем----\n";
    int result = price / (entrance * apartment);
    cout << "Каждая квартира должна заплатить по " << result << " руб";
}

int main() {
    housingCosts();
    return 0;
}