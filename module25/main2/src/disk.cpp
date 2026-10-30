#include <iostream>
#include <fstream>
#include <vector>
#include "disk.h"
#include "ram.h"
using namespace std;

void load(){
    vector<int> buffer(8);
    ifstream file("save.bin", ios::binary);
    if (!file.is_open()){
        cout << "error open file" << endl;
        file.close();
        return;
    }
    for (int i = 0; i < buffer.size(); i++){
        file.read((char*)&buffer[i], sizeof(buffer[i]));
    }
    file.close();
    write(buffer);
    cout << "Buffer load" << endl;
}

void save(){
    vector<int> buffer(8);
    read(buffer);
    ofstream file("save.bin", ios::binary);
    for (int i = 0; i < buffer.size(); i++){
        file.write((char*)&buffer[i], sizeof(buffer[i]));
    }
    file.close();
    cout << "Buffer save" << endl;
}