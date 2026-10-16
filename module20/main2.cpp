#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int width, height;
    cout << "Input width and height: ";
    cin >> height >> width;

    while (width < 0 || height < 0){
        cout << "Error. Invalid input. Try again" << endl;
        cout << "Input width and height: ";
        cin >> width >> height;
    }
    srand(time(nullptr)); // начальное зерно случ чисел в зависимоти от времени

    ofstream file("pic.txt");
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            file << rand() % 2;
        }
        file << endl;
    }
    file.close();

    return 0;
}