#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string userFish;
    cout << "Input type of fish: ";
    cin >> userFish;

    ifstream riverFile("river.txt");
    ofstream basketFile("basket.txt", ios::app);
    
    while(!riverFile.eof()){
        string riverFish;
        riverFile >> riverFish;
        if (riverFish == userFish){
            basketFile << riverFish << endl;;
        }
    }

    basketFile.close();
    riverFile.close();
    return 0;
}