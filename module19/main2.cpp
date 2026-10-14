#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    string pathFile;
    cout << "Only .txt file\nInput path file: ";
    cin >> pathFile;

    ifstream file;
    file.open(pathFile, ios::binary);
    while (!file.is_open()){
        cout << "ERROR. Try again\nOnly .txt file\nInput path file: ";
        cin >> pathFile;
        file.open(pathFile, ios::binary);
    }

    char buffer[20]; // будем считывать по частям, по 20 байт
    int i = 0;
    while (!file.eof()){
        file.read(buffer, sizeof(buffer));
        for (int i = 0; i < file.gcount(); i++){ // вывдим все, то что считали
            cout << buffer[i];
        }
    }
    

    file.close();
}