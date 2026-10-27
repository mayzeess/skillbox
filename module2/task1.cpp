#include <iostream>
using namespace std;

void racer(){
    int lapNumber = 4;
    string driver = "Шумахер";
    int engineCar = 254;
    int wheelCar = 93;
    int steeringWheel = 49;
    int weatherWind = -21;
    int weatherRain = -17;
    int speed = engineCar + wheelCar + steeringWheel + weatherWind + weatherRain;

    cout << "================\n";
    cout << "Супер гонки. Круг " << lapNumber << "\n";
    cout << "================\n";
    cout << driver << "(" << speed << ")\n";
    cout << "================\n";
    cout << "Водитель: " << driver << "\n";
    cout << "Скорость: " << speed << "\n";
    cout << "----------------\n" << "Оснащение" << "\n";
    cout << "Двигатель: +" << engineCar << "\n";
    cout << "Колеса: + " << wheelCar << "\n";
    cout << "Руль: +" << steeringWheel << "\n";
    cout << "----------------\n" << "Действия плохой погоды" << "\n";
    cout << "Ветер: " << weatherWind << "\n";
    cout << "Дождь: " << weatherRain << "\n";
}

int main() {
    racer();
    return 0;
}