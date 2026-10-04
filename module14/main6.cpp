#include <iostream>
using namespace std;


void printArr(int arr[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}


int main(){
    int multiplier = 1, number = 0;
    const int n = 5;
    const int m = 5;
    int arr[n][m];

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j * multiplier + (1 - multiplier) * 2] = number;
            number += 1;
        }
        multiplier *= -1;
    }

    printArr(arr);
    return 0;
}