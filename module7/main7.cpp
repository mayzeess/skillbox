#include <iostream>
using namespace std;

int main(){
    int n, x;
    cout << "Введите количество бактерий: ";
    cin >> n;
    cout << "Введите количество антибиотика: ";
    cin >> x;

    int kill = 10;

    for(int i = 0; n > 0 && kill > 0; i++) {
        n *= 2;
        n -= x * kill;
        kill--;
        if (n < 0) n = 0;
        cout << "После " << i + 1 << " часа бактерий осталось " << n << "\n";
    }
    return 0;
}