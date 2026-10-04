#include <iostream>
#include <vector>
using namespace std;

vector<vector<float>> inputMatrix(){
    vector<vector<float>> matrix(4, vector<float>(4));
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << "Input matrix element " << i << " " << j << " : ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

void printMatrix(vector<vector<float>> matrix){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printMatrix1(vector<float> matrix){
    for (int i = 0; i < 4; i++){
        cout << matrix[i] << "\t";
        cout << "\n";
    }
    cout << "\n";
}

vector<float> multiplyMatrix(vector<vector<float>> a, vector<float> b){
    vector<float> c(4);

    for (int i = 0; i < 4; i++){
        float temp = 0;
        for (int j = 0; j < 4; j++){
            temp += a[i][j] * b[j];
        }
        c[i] = temp;
    }
    
    return c;
}

int main(){
    cout << "Input matrix A: \n";
    vector<vector<float>> a = inputMatrix();
    cout << "Input matrix B: \n";
    vector<float> b(4);
    
    for (int i = 0; i < 4; i++){
        cout << "Input element b" << i << " : ";
        cin >> b[i];
    }

    cout << "Matrix A * B\n";
    printMatrix(a);
    cout << "*\n";
    printMatrix1(b);

    cout << "Result matrix C:\n";
    vector<float> c = multiplyMatrix(a, b);

    printMatrix1(c);

    return 0;
}