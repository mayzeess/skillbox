#include <iostream>
#include <vector>
#include "gpu.h"
using namespace std;

void printBuffer(vector<int>& buffer){
    cout << "Buffer: ";
    for (int i = 0; i < buffer.size(); i++){
        cout << buffer[i] << " ";
    }
    cout << endl;
}