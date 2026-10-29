#include <iostream>
#include <fstream>
#include <vector>
#include "disk.h"
using namespace std;

void load(vector<int>& v){
    v.resize(8);
    ifstream file("save.bin", ios::binary);
    if (!file.is_open()){
        cout << "error open file" << endl;
        file.close();
        return;
    }
    for (int i = 0; i < v.size(); i++){
        file.read((char*)&v[i], sizeof(v[i]));
    }
    file.close();
    cout << "Buffer load" << endl;
}

void save(vector<int>& v){
    ofstream file("save.bin", ios::binary);
    for (int i = 0; i < v.size(); i++){
        file.write((char*)&v[i], sizeof(v[i]));
    }
    file.close();
    cout << "Buffer save" << endl;
}