#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> inputMatrix(){
    vector<vector<int>> matrix(4, vector<int>(4));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << "Input matrix element " << i << " " << j << " : ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(vector<vector<int>> matrix){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool comparisonMatrix(vector<vector<int>> matrix1, vector<vector<int>> matrix2){
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if (matrix1[i][j] != matrix2[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

vector<vector<int>> transformationDiagonalMatrix(vector<vector<int>> matrix){
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if (i == j){
                continue;
            }
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

int main(){
    cout << "Input matrix 1: ";

    vector<vector<int>> matrix1 = inputMatrix();
    vector<vector<int>> matrix2 = inputMatrix();

    cout << "Matrix 1: \n";
    printMatrix(matrix1);
    cout << "Matrix 2: \n";
    printMatrix(matrix2);

    if (comparisonMatrix(matrix1, matrix2)){
        cout << "matrix1 = matrix2\nDiagonal matrix: \n";
        matrix1 = transformationDiagonalMatrix(matrix1);
        printMatrix(matrix1);
    }
    else{
        cout << "matrix1 != matrix2\nEnd program.";
    }

    return 0;
}