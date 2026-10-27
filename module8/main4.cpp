#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float volume, speedInternet, downloaded = 0;
    cout << "Укажите размер файла для скачивания: ";
    cin >> volume;
    cout << "Какова скорость вашего соединения? ";
    cin >> speedInternet;

    if (volume <= 0 || speedInternet <= 0){
        cout << "Ошибка, данные должны быть больше 0";
        return 0;
    }

    for (int i = 1; downloaded < volume; i++){
        downloaded += speedInternet;
        if (downloaded > volume) downloaded = volume;
        cout << "Прошло " << i << " сек. Скачано " << downloaded << " из " << volume << " МБ " 
        << floorf(downloaded / (volume / 100.f)) << "%.\n";
    }
    return 0;
}