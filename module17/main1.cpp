#include <iostream>
using namespace std;

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int a, b;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;

    cout << "A = " << a << " B = " << b << endl;

    swap(&a, &b);

    cout << "After function: " << endl;
    cout << "A = " << a << " B = " << b << endl;
    return 0;
}