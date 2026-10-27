#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float f, m, t;
    cout << "Введите силу тяги в Ньютонах: ";
    cin >> f;
    cout << "Введите массу в кг: ";
    cin >> m;
    cout << "Введите время в секундах: ";
    cin >> t;

    float res = ((f / m) * powf(t, 2.f))/ 2.f;

    cout << "От первоначального положения космический корабль окажется на расстоянии " << res 
    << " метров через " << t << " секунд.";

    return 0;
}