#include <iostream>
using namespace std;

int nextStation(string stationName, int& passengersInCabin, int& money){
    int exit; 
    int entrance;
    cout << "Прибываем на остановку «" << stationName <<"». В салоне пассажиров: " << passengersInCabin << "\n";
    cout << "Сколько пассажиров вышло на остановке? ";
    cin >> exit;
    cout << "Сколько пассажиров зашло на остановке? ";
    cin >> entrance;
    money += entrance * 20;
    passengersInCabin -= exit;
    passengersInCabin += entrance;
    cout << "Отправляемся с остановки «" << stationName << "». В салоне пассажиров: " << passengersInCabin << "\n";
    cout << "-----------Едем---------\n";
    
    return(passengersInCabin);
}

void profitCalculation(int& money){
    cout << "Всего заработали: " << money << " руб.\n";
    cout << "Зарплата водителя: " << money/4 << " руб.\n";
    cout << "Расходы на топливо: " << money/5 << " руб.\n";
    cout << "Налоги: " << money/5 << "руб.\n";
    cout << "Расходы на ремонт машины: " << money/5 << " руб.\n";
    cout << "Итого доход: " << money - money/4 - money/5 - money/5 - money/5 << " руб.";    
}

void simulatorBus(){
    string stationName[] = {"Улица программистов", "Проспект алгоритмов", "Парк C++", "Улица объявления переменных"};
    // string station1 = "Улица программистов";
    // string station2 = "Проспект алгоритмов";
    // string station3 = "Парк C++";
    // string station4 = "Улица объявления переменных";

    int passengersInCabin = 0;
    int money = 0;

    // passengersInCabin = nextStation(station1, passengersInCabin, money);
    // passengersInCabin = nextStation(station2, passengersInCabin, money);
    // passengersInCabin = nextStation(station3, passengersInCabin, money);
    // passengersInCabin = nextStation(station4, passengersInCabin, money);

    // Чтобы избежать дублирования кода, все названия станций вынес в одномерный массив
    // и циклом вызывал функцию. Чтобы добавить еще станцию, нужно просто добавить ее в массив.
    for(int i = 0; size(stationName) > i; i++){
        passengersInCabin = nextStation(stationName[i], passengersInCabin, money);
    }

    profitCalculation(money);
}

int main(){
    cout << "Программа, симулятор маршрутки\n";
    simulatorBus();
    return 0;
}