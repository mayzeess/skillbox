#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

vector<int> addSaveData(vector<int> v){ // добавляем сохраненные данные из файла (если он есть)
    ifstream bank("bank.bin", ios::binary);
    if (!bank.is_open()){
        bank.close();
        return v;
    }
    for (int i = 0; i < v.size(); i++){
        if (!bank.read((char*)&v[i], sizeof(v[i]))) break;
    }
    bank.close();

    return v;
}

int sumBank(vector<int> v){ // считаем сумму всех денег в банке
    int sum = 0;
    for (int i = 0; i < v.size(); i++){
        sum += v[i];
    }
    return sum;
}

void printSateBank(vector<int> v){ // печатаем состояние банка
    ifstream bank("bank.bin", ios::binary);
    if (!bank.is_open()){
        cout << "The bank is empty." << endl;
        bank.close();
        return;
    }
    bank.close();

    cout << "Count 100 banknot: " << count(v.begin(), v.end(), 100) << endl;
    cout << "Count 200 banknot: " << count(v.begin(), v.end(), 200) << endl;
    cout << "Count 500 banknot: " << count(v.begin(), v.end(), 500) << endl;
    cout << "Count 1000 banknot: " << count(v.begin(), v.end(), 1000) << endl;
    cout << "Count 2000 banknot: " << count(v.begin(), v.end(), 2000) << endl;
    cout << "Count 5000 banknot: " << count(v.begin(), v.end(), 5000) << endl;
    cout << "Sum: " << sumBank(v) << endl;
}

int randomBanknote(int banknote){ // функция для определения ранломной купюры в банке
    if (banknote == 0){
        return 100;
    }
    else if (banknote == 1){
        return 200;
    }
    else if (banknote == 2){
        return 500;
    }
    else if (banknote == 3){
        return 1000;
    }
    else if (banknote == 4){
        return 2000;
    }
    
    return 5000;
}

void saveData(vector<int> v); 

vector<int> addBanknotes(vector<int> v){ // добавить недостающие банкноты
    for (int i = 0; i < v.size(); i++){
        if (v[i] != 0) continue;
        int banknote = rand() % 6;
        banknote = randomBanknote(banknote);
        v[i] = banknote;
    }

    saveData(v);
    return v;
}

vector<int> withdrawMoney(vector<int> v){ // функция снятия денег
    int countMoney;
    cout << "Input the amount of money: ";
    cin >> countMoney;
    if (countMoney > sumBank(v)){
        cout << "The bank doesn't have that much money." << endl;
        return v;
    }

    if(countMoney % 100 != 0){
        cout << "Operation impossible" << endl;
        return v;
    }

    for (int i = 0; countMoney != 0; i++){ // пока не снимем всю сумму идем и ищем подходящие купюры
        if(countMoney >= 5000 && v[i] == 5000){
            countMoney -= 5000;
            v[i] = 0;
            if (countMoney < 5000) { i = 0; } // если мы сняли купюру, а суммуа все еще больше данной купюры или равно, то мы продолжаем 
            // идти по циклу
            // если уже меньше, то идем по циклу заново.
        }

        else if(countMoney >= 2000 && v[i] == 2000){
            countMoney -= 2000;
            v[i] = 0;
            if (countMoney < 2000) { i = 0; }
        }

        else if(countMoney >= 1000 && v[i] == 1000){
            countMoney -= 1000;
            v[i] = 0;
            if (countMoney < 1000) { i = 0; }
        }

        else if(countMoney >= 500 && v[i] == 500){
            countMoney -= 500;
            v[i] = 0;
            if (countMoney < 500) { i = 0; }
        }

        else if(countMoney >= 200 && v[i] == 200){
            countMoney -= 200;
            v[i] = 0;
            if (countMoney < 200) { i = 0; }
        }

        else if(countMoney >= 100 && v[i] == 100){
            countMoney -= 100;
            v[i] = 0;
            if (countMoney < 100) { i = 0; }
        }
    }
    saveData(v);

    return v;
}

void saveData(vector<int> v){ // функция сохранения данных в файл
    ofstream file("bank.bin", ios::binary);
    for (int i = 0; i < v.size(); i++){
        file.write((char*)&v[i], sizeof(v[i]));
    }
    file.close();
}

int main(){
    int maxBanknot = 1000;
    vector<int> money(maxBanknot, 0);
    money = addSaveData(money);
    cout << "Command:\n+: fill in the missing banknotes.\n-: withdraw money.\n0: exit program.\n";
    cout << "Input only: +, -, 0\n" << endl;
    char command;
    while (true){
        printSateBank(money);
        cout << "Input command: ";
        cin >> command;
        if (command == '+'){
            money = addBanknotes(money);
        }
        else if(command == '-'){
            money = withdrawMoney(money);
        }
        else if (command == '0'){
            cout << "Exit program\n";
            break;
        }
        else {
            cout << "Invalid input. Try again,\n";
            cout << "Input only: +, -, 0\nInput command: " << endl;
        }
    }
    
    return 0;
}