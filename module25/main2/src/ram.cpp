#include <iostream>
#include <vector>
#include "ram.h"
using namespace std;

void write(vector<int>& v){
    v.clear();
    int x;
    for (int i = 0; i < 8; i++){
        cout << "Input " << i + 1 << " element: ";
        cin >> x;
        v.push_back(x);
    }
    cout << "Bufer saved" << endl;
}

void read(vector<int>& v){
    if (v.size() < 8){
        cout << "insufficient data" << endl;
        return;
    }
    
    cout << "Buffer: ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}