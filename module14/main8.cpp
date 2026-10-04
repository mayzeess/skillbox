#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool fieldSize(int x){ // проверка на то, попали ли значения в размер поля
    if (x < 0 || x < 0 || x > 9 || x > 9){
        return false;
    }
    return true;
}

bool validInput(vector<vector<char>> field, int i, int x1, int x2, int y1, int y2){ // проверка на коррекнтый ввод координат
    if (!fieldSize(x1) || !fieldSize(x2) || !fieldSize(y1) || !fieldSize(y2) || field[x1][x2] != '0' || field[y1][y2] != '0'){
        return false;
    }
    if (i < 4){
        return true;
    }

    int temp1 = abs(x1 - y1);
    int temp2 = abs(x2 - y2);
    if (i < 7){
        if (temp1 == 0 && temp2 == 1 || temp1 == 1 && temp2 == 0){
            return true;
        }
        return false;
    }

    else if (i < 9){
        if (temp1 == 0 && temp2 == 2 || temp1 == 2 && temp2 == 0){
            for (int i = x1; i <= y1; i++){
                for (int j = x2; j <= y2; j++){
                    if (field[i][j] != '0'){
                        return false;
                    }
                }
            }
        }
        else {
            return false;
        }
        return true;
    }

    else {
        if (temp1 == 0 && temp2 == 3 || temp1 == 3 && temp2 == 0){
            for (int i = x1; i <= y1; i++){
                for (int j = x2; j <= y2; j++){
                    if (field[i][j] != '0'){
                        return false;
                    }
                }
            }
        }
        else {
            return false;
        }
        return true;
    }
}


// совершить выйстрел
vector<vector<char>> shoot(vector<vector<char>> field, int x, int y){
    while (!fieldSize(x) || !fieldSize(y)){
        cout << "Try again. Field 0-9 coordinates\n";
        cout << "Input shoot coordinates: ";
        cin >> x >> y;
    }
    if (field[x][y] == 'X'){
        cout << "The ship has been hit.\n";
        field[x][y] = ' ';
    }
    else {
        cout << "Miss.\n";
        field[x][y] = 'm';
    }

    return field;
}

// вывести поле
void printField(vector<vector<char>> field){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cout << field[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

//чей следующий ход
bool nextMove(vector<vector<char>> field, int x, int y, bool nextPlayerMove){
    if (field[x][y] == ' '){
        return nextPlayerMove;
    }
    return !nextPlayerMove;
}

// расставление короблей на поле
vector<vector<char>> shipDeployment(vector<vector<char>> field){
    for (int i = 0; i < 10; i++){
        int x1, x2, y1, y2;
        cout << "Input ship number " << i + 1 << " :\n";
        if (i < 4){
            cout << "1 cell ship.\nInput coordinate: ";
            cin >> x1 >> x2;
            while(!validInput(field, i, x1, x2, x1, x2)){
                cout << "Try again\n";
                cout << "Input coordinate: ";
                cin >> x1 >> x2;
            }
            field[x1][x2] = 'X';
        }
        else if (i < 7){
            cout << "2 cell ship.\nInput coordinate 1: ";
            cin >> x1 >> x2;
            cout << "Input coordinate 2: ";
            cin >> y1 >> y2;
            while(!validInput(field, i, x1, x2, y1, y2)){
                cout << "Try again\n";
                cout << "Input coordinate 1: ";
                cin >> x1 >> x2;
                cout << "Input coordinate 2: ";
                cin >> y1 >> y2;
            }
            field[x1][x2] = 'X';
            field[y1][y2] = 'X';
        }
        else if (i < 9){
            cout << "3 cell ship.\nInput coordinate 1: ";
            cin >> x1 >> x2;
            cout << "Input coordinate 2: ";
            cin >> y1 >> y2;
            while(!validInput(field, i, x1, x2, y1, y2)){
                cout << "Try again\n";
                cout << "Input coordinate 1: ";
                cin >> x1 >> x2;
                cout << "Input coordinate 2: ";
                cin >> y1 >> y2;
            }
            for (int i = x1; i <= y1; i++){
                for (int j = x2; j <= y2; j++){
                    field[i][j] = 'X';
                }
            }
        }
        else{
            cout << "4 cell ship.\nInput coordinate 1: ";
            cin >> x1 >> x2;
            cout << "Input coordinate 2: ";
            cin >> y1 >> y2;
            while(!validInput(field, i, x1, x2, y1, y2)){
                cout << "Try again\n";
                cout << "Input coordinate 1: ";
                cin >> x1 >> x2;
                cout << "Input coordinate 2: ";
                cin >> y1 >> y2;
            }
            for (int i = x1; i <= y1; i++){
                for (int j = x2; j <= y2; j++){
                    field[i][j] = 'X';
                }
            }
        }
    }

    return field;
}

// проверка на поражение
bool loss(vector<vector<char>> field){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (field[i][j] == 'X'){
                return 0;
            }
        }
    }

    return 1;
}

int main(){

    cout << "Battleship\n";
    cout << "0 - empty cell\n";
    cout << "X - cage with a ship\n";
    cout << "' ' - hit on the ship\n";
    cout << " m - shot miss\n";
    vector<vector<char>> player1(10, vector<char>(10, '0'));
    vector<vector<char>> player2(10, vector<char>(10, '0'));

    cout << "Field player 1: \n";
    printField(player1);
    cout << "Field player 2: \n";
    printField(player2);

    cout << "Player 1 input ships: \n";
    player1 = shipDeployment(player1);
    cout << "Field player 1: \n";
    printField(player1);
    cout << "Player 2 input ships: \n";
    player2 = shipDeployment(player2);
    cout << "Field player 2: \n";
    printField(player2);

    int x, y; // координаты выстрела

    bool nextPlayerMove = 1; // кто ходит следующим. Если игрок попал, то ходит еще раз.
    while (!loss(player1) && !loss(player2)){
        cout << "Player 1 field:\n";
        printField(player1);

        cout << "Player 2 field:\n";
        printField(player2);

        if (nextPlayerMove){
            cout << "Player 1. - shoot.\n";
            cout << "Input shoot coordinates: ";
            cin >> x >> y;

            player2 = shoot(player2, x, y);
            nextPlayerMove = nextMove(player2, x, y, nextPlayerMove);
        }
        else {
            cout << "Player 2. - shoot.\n";
            cout << "Input shoot coordinates: ";
            cin >> x >> y;
            player1 = shoot(player1, x, y);
            nextPlayerMove = nextMove(player1, x, y, nextPlayerMove);
        }
    }

    if (loss(player1)){
        cout << "Player 2 WIN.\nEND GAME.";
    }
    else {
        cout << "Player 1 WIN.\nEND GAME.";
    }

    return 0;
}