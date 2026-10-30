#include <iostream>
#include <vector>
#include "cpu.h"
#include "ram.h"
using namespace std;

void compute(){
    int sum = 0;
    vector<int> buffer;
    read(buffer);
    for (int i = 0; i < buffer.size(); i++){
        sum += buffer[i];
    }
    cout << "Sum: " << sum << endl;
}