#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float amplitudeStart, amplitudeEnd, stop;
    cout << "Введите начальную амплитуду колебания в санитметарах: ";
    cin >> amplitudeStart;
    cout << "Введите конечную амплитуду колебания в санитметарах: ";
    cin >> amplitudeEnd;

    if (amplitudeStart < amplitudeEnd || amplitudeEnd <= 0){
        cout << "Начальная амплитуда должна быть больше конечной.\n";
        cout << "Также конечная амплитуда должны бать больше 0";
        return 0;
    }

    int res = 0;
    while (amplitudeStart > amplitudeEnd){
        amplitudeStart -= (amplitudeStart / 100.f) * 8.4f;
        res++;
    }

    cout << "Маятник кочнется " << res << " раз(a)";
    return 0;
}