#include <iostream>
using namespace std;

int main(){
    int speedPlane;
    int heightPlane;

    cout << "Напишите скорость самолета: ";
    cin >> speedPlane;
    if (speedPlane <= 0) {
        cout << "Скорость должна быть выше нуля";
        return 0;
    }
    cout << "Напишите высоту самолета: ";
    cin >> heightPlane;
    if (heightPlane <= 0) {
        cout << "Высота должна быть выше нуля";
        return 0;
    }
    if (speedPlane >= 750 && speedPlane <= 850 && heightPlane >= 9000 && heightPlane <= 9500){
        cout << "Самолет летит правильно";
    } else {
        cout << "Самолет летит не правильно";
    }
    return 0;
}