#include <iostream>
using namespace std;

enum note
{
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main(){
    string accord;
    cout << "Input accord: ";
    cin >> accord;

    int notes = 0;
    for (int i = 0; i < accord.length(); i++){
        int temp = accord[i] - '0'; // atoi(accord[i]) не работает, нужен const char*
        if (temp < 0 || temp > 7){
            cout << "Error";
            return 0;
        }
        notes |= 1 << (temp - 1);
    }

    cout << "Bit mask: " << notes << endl;
    if (notes & DO)
    {
        cout << "DO ";
    }
    if (notes & RE){
        cout << "RE ";
    }
    if (notes & MI){
        cout << "MI ";
    }
    if (notes & FA){
        cout << "FA ";
    }
    if (notes & SOL){
        cout << "SOL ";
    }
    if (notes & LA){
        cout << "LA ";
    }
    if (notes & SI){
        cout << "SI ";
    }
    return 0;
}