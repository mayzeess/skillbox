#include <iostream>
#include <vector>
using namespace std;

bool printMatrix(vector<vector<bool>> matrix, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j]) {
                cout << "O" << "\t";
            }
            else {
                cout << "X" << "\t";
                count++;
            }
        }
        cout << "\n";
    }
    cout << "\n";

    if (count == (n * m)) {
        return 1;
    }

    return 0;
}

vector<vector<bool>> burstRegion(vector<vector<bool>> matrix, int n, int m) { // функция лопания региона
    int x1, x2, y1, y2;
    cout << "Input x: ";
    cin >> x1 >> x2;
    cout << "Input y: ";
    cin >> y1 >> y2;

    while (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 > n - 1 || x2 > m - 1 || y1 > n - 1 || y2 > m - 1 || x1 > y1 || x2 > y2) {
        cout << "Try again. Format: 1 1\n\n";
        cout << "Input x: ";
        cin >> x1 >> x2;
        cout << "Input y: ";
        cin >> y1 >> y2;
    }

    for (int i = x1; i <= y1; i++) {
        for (int j = x2; j <= y2; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}



int main() {
    const int n = 12;
    const int m = 12;
    vector<vector<bool>> bubbleWrap(n, vector<bool>(m, 1)); // вектор сразу заполненный 1 (true)
    bool allBurst = printMatrix(bubbleWrap, n, m);


    while (!allBurst) {
        bubbleWrap = burstRegion(bubbleWrap, n, m);
        allBurst = printMatrix(bubbleWrap, n, m);
    }


    return 0;
}