#include <iostream>
using namespace std;

int main(){
    int beginHeight = 100;
    int dailyGrowth = 50;
    int nightFade = 20;
    int day;

    cout << "Программа для подсчета высоты бамбука.\nНапишите к середине какого дня вы хотите посчитать высоту: ";
    cin >> day;
    int result = beginHeight + (dailyGrowth - nightFade) * day + dailyGrowth / 2;

    cout << "К середине " << day << " дня, высота бамбука составит " << result;
    return 0;
}