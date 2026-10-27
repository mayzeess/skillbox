#include <iostream>
using namespace std;

int main(){
    int width, height;
    cout << "Напишите высоту и ширину ";
    cin >> width >> height;

    for(int x = 0; width > x; x++){
        for(int y = 0; height > y; y++){
            if (y == 0 || (y == height - 1)) cout << "|";
            else if (x == 0 || (x == width - 1)) cout << "-";
            else cout << " ";
        }
        cout << "\n";
    }
    return 0;
}