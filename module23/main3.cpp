#include <iostream>
#include <vector>
using namespace std;

#define OVERFLOW(func, n) { func(n); }

#define INPUT(func) {for(int i = 0; i < 10; i++) { func(i);} }

void printOVerflow(int n) {
    if (n > 20){
        cout << "carriage number " << n << " overflow. (20/" << n << ")" << endl;
    }
    else if (n < 20){
        cout <<  "there are spots available (" << n << "/20)" << endl;
    }
    else {
        cout << "there are exactly 20 passengers" << endl;
    }
}

void inputNumber(int n){
    cout << "Input count passengers number " << n + 1 << " : ";
    int x;
    cin >> x;
    OVERFLOW(printOVerflow, x);
}



int main(){
    INPUT(inputNumber);
    return 0;
}