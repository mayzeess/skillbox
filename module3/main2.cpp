#include <iostream>
using namespace std;

int main(){
    int a = 77729;
    int b = 1947;
    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
    // Способ 1
    // swap(a, b);

    // Способ 2
    // int c = a;
    // a = b;
    // b = c;

    // Способ 3
    a = b - a;
    b -= a;
    a += b;
    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
    return 0;
}
