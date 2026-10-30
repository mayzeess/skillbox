#include <iostream>
#include <vector>
#include "ram.h"
using namespace std;

vector<int> buffer(8);

void write(vector<int>& v){
    for (int i = 0; i < buffer.size(); i++){
        buffer[i] = v[i];
    }
}

void read(vector<int>& v){
    for (int i = 0; i < buffer.size(); i++){
        v[i] = buffer[i];
    }
}