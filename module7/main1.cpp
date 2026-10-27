#include <iostream>
using namespace std;

int main(){
    int buckwheat = 100;
    cout << "Всего гречки было на начало подсчёта: " << buckwheat << " кг\n";
    for(int i = 1; buckwheat != 0; i++){
        buckwheat -= 4;
        cout << "После " << i << " месяца у вас в запасе останется " << buckwheat << " кг гречки\n";
    }

    return 0;
}