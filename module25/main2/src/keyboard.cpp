#include <iostream>
#include <vector>
#include "keyboard.h"
#include "ram.h"
using namespace std;

void inputBuffer(){
    vector<int> v;
    int x;
    for (int i = 0; i < 8; i++){
        cout << "Input " << i + 1 << " element: ";
        cin >> x;
        v.push_back(x);
    }
    write(v);
    cout << "Bufer saved" << endl;
}