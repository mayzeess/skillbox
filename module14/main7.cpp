#include <iostream>
using namespace std;

int main(){
    int arr[5][5][10];


    for (int i = 0; i < 5; i++){ // полностью заполняем нулями
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 10; k++){
                arr[i][j][k] = 0;
            }
        }
    }

    cout << "input matrix of heights: \n"; // вводим значения
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cin >> arr[i][j][0];
        }
    }

    for (int i = 0; i < 5; i++){ // заполняем единицаме, где это надо
        for (int j = 0; j < 5; j++){
            int x = arr[i][j][0];
            for (int k = 0; k <= x; k++){
                arr[i][j][k] = 1;
            }
        }
    }

    int h;
    cout << "input slice: ";
    cin >> h;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << arr[i][j][h] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}