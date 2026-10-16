#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string name, surname, date;
    int money;
    bool is_valid;
    cout << "-1: exit program\n";
    ofstream file("statement.txt");

    while (true){
        is_valid = true;
        cout << "Input name: ";
        cin >> name;
        if (name == "-1") {return 0; }

        cout << "Input surname: ";
        cin >> surname;
        if (surname == "-1") {return 0; }

        cout << "Input date: ";
        cin >> date;
        // проверка корректного ввода числа и месяца 
        // (слабая проверка, не учитывается високосный год, количестко дней в зависимости от месяца)
        is_valid = stoi(date.substr(0, 2)) > 0 && stoi(date.substr(0, 2)) < 32 && stoi(date.substr(3, 2)) > 0 && stoi(date.substr(3, 2)) < 13;
        if (date == "-1") {return 0; }

        cout << "Input money: ";
        cin >> money;
        if (money == -1) {return 0; }

        if (is_valid){
            file << name << " " << surname << " " << date << " " << money << " " << endl;
            cout << "entry added" << endl;
        }
        else {
            cout << "entry not added. Error input" << endl;
        }
    }

    file.close();
    return 0;
}