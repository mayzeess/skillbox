#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct statement {
    string name;
    string surname;
    string date;
    int money;
};

void add(ofstream& file, statement& employee){

    cout << "Input name: ";
    cin >> employee.name;
    cout << "Input surname: ";
    cin >> employee.surname;
    cout << "Input date: ";
    cin >> employee.date;
    cout << "Input money: ";
    cin >> employee.money;

    file << employee.name << " ";
    file << employee.surname << " ";
    file << employee.date << " ";
    file << employee.money << endl;   
}

void list(ifstream& file){
    if (!file.is_open()){
        cout << "error open file";
        return;
    }

    statement employee;
    while(!file.eof()){
        file >> employee.name;
        if (file.eof()) { break; }
        file >> employee.surname >> employee.date >> employee.money;
        cout << employee.name << " " << employee.surname << " " << employee.date << " " << employee.money << endl;
    }
}

// только немного не понял зачем использовать именно вектор.  (В задании написано: Используйте вектор структур.)
// вся информация у нас в файле, можно было просто записывать данные в файл по команде add
// а по команде list - показывать содерджимое файла на экран
// тогда функция add, не принимала бы структуру, а создавала бы ее внутри функции, по аналогии с list


int main(){
    string command;
    vector<statement> employee; // вектор (массив) структур
    int i = 0;
    cout << "Input exit, to exit the program\n";
    while (true){
        cout << "Input command: ";
        cin >> command;
        if (command  == "list"){
            ifstream file("statement.txt"); // записываем в конец файла
            list(file);
            file.close();
        }
        else if (command == "add"){
            ofstream file("statement.txt", ios::app);
            employee.resize(employee.size() + 1); // меняю размер вектора, добавляю запись
            add(file, employee[i]);
            file.close();
            i++;
        }
        else if (command == "exit"){
            cout << "End program";
            return 0;
        }
        else {
            cout << "Error input. Try again.\n";
        }
    }
    return 0;
}