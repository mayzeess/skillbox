#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? ";
    float distance, allTime = 0;
    cin >> distance;

    if (distance < 1) {cout << "Минимальная дистанция 1 км"; return 0;}

    for(int i = 0; i < distance; i++){
        cout << "Какой у тебя был темп на километре " << i + 1 << "? ";
        float time;
        cin >> time;
        if (time < 1) {cout << "такого быть не может\n"; i--; continue;}
        allTime += time;
    }

    float minutes = (allTime / distance) / 60;
    float sec = (minutes - floorf(minutes)) * 60;

    cout << "Твой средний темп за тренировку: " << floorf(minutes) << " минуты " << roundf(sec) << " секунд";
    return 0;
}