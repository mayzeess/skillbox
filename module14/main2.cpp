#include <iostream>
using namespace std;

void printGame(char game[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << game[i][j] << " ";
        }
        cout  << "\n";
    }
}

bool winGame(char game[3][3]){
    bool win = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (game[i][j] == ' '){
                continue;
            }
            int countLine = 0; // переменная для проверки строк
            int countRow = 0; // для проверки столбцов
            int temp = game[i][j];
            for (int k = 0; k < 3; k++){
                if (game[i][j] == game[i][k]){
                    countLine++;
                }
                if (game[i][j] == game[k][j]){
                    countRow++;
                }
            }
            if (countLine == 3 || countRow == 3){
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    char game[3][3] = {{' ', ' ', ' '},
                       {' ', ' ', ' '},
                       {' ', ' ', ' '}};

    cout << "Format input: 1 1.\n";
    for (int i = 0; i < 9; i++){
        int w, h;
        if (i % 2 == 0){
            cout << "Input plaer 1 - X: ";
        } 
        else {
            cout << "Input plaer 2 - 0: ";
        }
        
        cin >> h >> w;
        while (w < 0 || w > 2 || h > 2 || h < 0){
            cout << "Try again. Index error\n";
            cin >> h >> w;
        }

        while (game[w][h] != ' '){
            cout << "It is locate: " << game[w][h] << ". Try again.\n";
            cin >> h >> w;
        }

        if (i % 2 == 0){
            game[w][h] = 'X';
        }
        else {
            game[w][h] = '0';
        }

        cout << "\n";
        printGame(game);
        cout << "\n";

        if (winGame(game)){
            if (i % 2 == 0){
            cout << "Player 1 - X. WIN";
            } 
            else {
                cout << "Player 2 - 0. WIN";
            }
            break;
        }
    }
    return 0;
}