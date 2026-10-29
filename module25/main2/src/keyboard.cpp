#include <iostream>
#include <vector>
#include "keyboard.h"
using namespace std;

void inputBuffer(vector<int>& v){
    v.clear();
    int x;
    for (int i = 0; i < 8; i++){
        cout << "Input " << i + 1 << " element: ";
        cin >> x;
        v.push_back(x);
    }
    cout << "Bufer saved" << endl;
}