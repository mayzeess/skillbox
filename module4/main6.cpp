#include <iostream>
using namespace std;

void barbershop(){
    cout << "Посчитаем хватает ли мастеров в барбершопе\n";
    int male;
    int mastersInBarbershop;
    int barberPerMonth = 8 * 30;
    cout << "Введите сколько мужчин проживает в вашем городе: ";
    cin >> male;
    cout << "Сколько работают барберов во всех барбершопах: ";
    cin >> mastersInBarbershop;

    cout << mastersInBarbershop * barberPerMonth << " - столько людей смогут обслужить барберы за 30 дней\n";

    int needBarbers = male / (barberPerMonth);
    if (needBarbers % barberPerMonth != 0){
        needBarbers += 1;
    }

    cout << "Необходимое число барберов " << needBarbers << "\n";
    cout << needBarbers << " барбера могут подстрич " << needBarbers * barberPerMonth << "\n";

    if (needBarbers > mastersInBarbershop) {
        cout << "нужно больше барберов";
    } 
    else {
        cout << "Барберов хвататет";
    }
}

int main(){
    barbershop();
    return 0;
}