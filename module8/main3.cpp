#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float x, y, z;
    cout << "Введите размеры бруска:\n";
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Z: ";
    cin >> z;

    if (x <= 0 || y <= 0 || z <=0 ){
        cout << "Ошибка, все размеры должны быть больше 0\n";
        return 0;
    }

    int count = ((int) x / 5) * ((int) y / 5) * ((int)z / 5);
    cout << "Можно изготовить " << count << " кубиков\n";

    int kit = 0;
    for (int i = 0; count - kit > kit; i++){
        kit = pow(i, 3);
    }

    cout << "Из них можно составить набор из " << kit << " кубиков";

    return 0;
}