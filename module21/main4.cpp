#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

struct persone{
    string name;
    int health;
    int armor;
    int damage;
    int x = 0; // координаты на поле
    int y = 0;
};

void characterCreation(persone& player){
    cout << "Input name player: ";
    cin >> player.name;
    cout << "Input health: ";
    cin >> player.health;
    cout << "Input armor: ";
    cin >> player.armor;
    cout << "Input damage: ";
    cin >> player.damage;
}


void createEnemy(vector<persone>& enemy, int count){ // 
    for (int i = 0; i < count; i++){
        enemy[i].name = "Enemy #" + to_string(i + 1);
        enemy[i].health = (rand() % 101 + 50); // от 50 до 150
        enemy[i].armor = (rand() % 50);
        enemy[i].damage = (rand() % 16 + 15);
    }

    cout << "\nCreated enemies:\n" << "name\t\thealth\tarmor\tdamage\n";
    for (int i = 0; i < count; i++){
        cout << enemy[i].name << "\t" << enemy[i].health << "\t" << enemy[i].armor << "\t" << enemy[i].damage << endl;
    }
}

void printField(vector<vector<char>>& v, persone& player, vector<persone>& enemy){ // выводим неше поле и статы игрока с врагами
    cout << player.name << " Health: " << player.health << " Armor: " << player.armor << " Damage: " << player.damage << endl; // выводим состонние игрока
    cout << "\nEnemies:\n" << "name\t\thealth\tarmor\tdamage\n";
    for (int i = 0; i < enemy.size(); i++){
        cout << enemy[i].name << "\t" << enemy[i].health << "\t" << enemy[i].armor << "\t" << enemy[i].damage << endl;
    }
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void randomPositions(vector<vector<char>>& v, persone& player, vector<persone>& enemy){ // функция для расставления игроков и соперников в случайные позиции
    player.x = rand() % 20;
    player.y = rand() % 20;
    v[player.x][player.y] = 'P';
    for (int i = 0; i < enemy.size(); i++){
        enemy[i].x = rand() % 20;
        enemy[i].y = rand() % 20;
        if (v[enemy[i].x][enemy[i].y] == '.'){ // расставляю игроков, проверяю что на месте находится '.'
            v[enemy[i].x][enemy[i].y] = 'E';
        }
        else {
            i--;
            continue;
        }
    }
}

void damage(persone& player, persone& enemy, bool shot){ // bool shot, булева переменная, которая говорит, кто кого ударил
    // true - игрок ударил врага, false - враг ударил игрока. Как определяется (внутри программы сначала ходит игрок, а потом враг)
    // если игрок сходил в клетку где был враг - ударил игрок, если враг сходил на клетку, где стоял игрок - ударил враг
    if (shot){
        enemy.armor -= player.damage;
        if (enemy.armor < 0){
            enemy.health += enemy.armor;
            enemy.armor = 0;
        }
        if (enemy.health <= 0){
            enemy.health = 0;
        }
    }
    else {
        player.armor -= enemy.damage;
        if (player.armor < 0){
            player.health += player.armor;
            player.armor = 0;
        }
        if (player.health <= 0){
            player.health = 0;
        }
    }
}

void moveEnemy(vector<vector<char>>& v, vector<persone>& enemy){ // рандомно ходят враги
    for (int i = 0; i < enemy.size(); i++){
        int move = rand() % 4; // рандом от 0 до 3
        if (move == 0){
            if (enemy[i].x > 0 && v[enemy[i].x - 1][enemy[i].y] == '.'){
                v[enemy[i].x][enemy[i].y] = '.';
                enemy[i].x--;
                v[enemy[i].x][enemy[i].y] = 'E';                
            }
        }
        else if (move == 1){
            if (enemy[i].x < 19 && v[enemy[i].x + 1][enemy[i].y] == '.'){
                v[enemy[i].x][enemy[i].y] = '.';
                enemy[i].x++;
                v[enemy[i].x][enemy[i].y] = 'E';
            }
        }
        else if (move == 2){
            if (enemy[i].y > 0 && v[enemy[i].x][enemy[i].y - 1] == '.'){
                v[enemy[i].x][enemy[i].y] = '.';
                enemy[i].y--;
                v[enemy[i].x][enemy[i].y] = 'E';
            }
        }
        else if (move == 3){
            if (enemy[i].y < 19 && v[enemy[i].x][enemy[i].y + 1] == '.'){
                v[enemy[i].x][enemy[i].y] = '.';
                enemy[i].y++;
                v[enemy[i].x][enemy[i].y] = 'E';
            }
        }
    }
}

persone& searchEnemy(vector<persone>& enemy, int x, int y){ // функция для поиска того самого врага, которого ударил игрок
    for (int i = 0; i < enemy.size(); i++){
        if (enemy[i].x == x && enemy[i].y == y){
            return enemy[i];
        }
    }
    return enemy[0];
}

void movePlayer(vector<vector<char>>& v, persone& player, vector<persone>& enemy){ // ходит игрок
    char move;
    cout << "0 - stop game. Input move:\n";
    while (true){
        cout << "Input move: ";
        cin >> move;
        if (move == 'w' && player.x > 0){
            if (v[player.x - 1][player.y] == 'E'){ // проверяю, елси игрок ходит туда, где стоит соперник, то наношу сопернику дамаг
                damage(player, searchEnemy(enemy, player.x - 1, player.y), true);
            }
            else { // елси нет, то просто обычный ход
                v[player.x][player.y] = '.';
                player.x--;
                v[player.x][player.y] = 'P';
            }
        }
        else if (move == 's' && player.x < 19){
            if (v[player.x + 1][player.y] == 'E'){
                damage(player, searchEnemy(enemy, player.x + 1, player.y), true);
            }
            else {
                v[player.x][player.y] = '.';
                player.x++;
                v[player.x][player.y] = 'P';
            }
        }
        else if (move == 'a' && player.y > 0){
            if (v[player.x][player.y - 1] == 'E'){
                damage(player, searchEnemy(enemy, player.x, player.y - 1), true);
            }
            else {
                v[player.x][player.y] = '.';
                player.y--;
                v[player.x][player.y] = 'P';
            }
        }
        else if (move == 'd' && player.y < 19){
            if (v[player.x][player.y + 1] == 'E'){
                damage(player, searchEnemy(enemy, player.x, player.y + 1), true);
            }
            else {
                v[player.x][player.y] = '.';
                player.y++;
                v[player.x][player.y] = 'P';
            }
        }
        else if (move == '0'){
            cout << "Stop game\n";
            break;
        }
        else {
            cout << "Error move. Try again. (w/a/s/d). 0 - stop game\n";
            continue;
        }
        moveEnemy(v, enemy);
        printField(v, player, enemy);
    }
}


int main(){
    string command;
    int countEnemy; // количество противников 
    
    while (true){
        vector<vector<char>> playingField(20, vector<char>(20, '.')); // игровое поле
        cout << "Command:\nstart - start new game\nload - load game\nquit - quit game\n";
        cout << "Input command: ";
        cin >> command;
        if (command == "load"){

        }

        else if (command == "start"){
            cout << "Input count enemy: ";
            cin >> countEnemy;
            persone player; // сам игрок
            vector<persone> enemy(countEnemy); // вектор противников
            characterCreation(player); // создается игрок
            createEnemy(enemy, countEnemy); // создаем противников
            randomPositions(playingField, player, enemy);
            cout << "To save the game - save\nPlayer control:\na - left\nd - right\nw - up\ns - down\n (w/a/s/d)\n"; 
            //вместо l,r,u,d сделал (w/a/s/d), так как так удобнее ходить
            printField(playingField, player, enemy);
            cout << "START GAME\n";
            movePlayer(playingField, player, enemy);
        }

        else if (command == "save"){

        }

        else if (command == "quit"){
            cout << "Thanks for the game\n";
            return 0;
        }
    }

    
    return 0;
}