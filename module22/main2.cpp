#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> surnameMap; // ключ - фамилия, значение - сколько таких фамилий
    string command;
    cout << "0 - Exit program\n";
    while (true) {
        cout << "Input: next or surname: ";
        cin >> command;
        if (command == "next") {
            if (surnameMap.begin() != surnameMap.end()) {
                cout << surnameMap.begin()->first << endl;
                map<string, int>::iterator it = surnameMap.begin();
                surnameMap[it->first]--;
                if (it->second == 0) {
                    surnameMap.erase(it);
                }
            }
            else {
                cout << "map empty" << endl;
            }
        }
        else if (command == "0") {
            cout << "Exit program";
            return 0;
        }
        else {
            if (surnameMap.find(command) == surnameMap.end()) {
                surnameMap.insert({ command, 1 });
            }
            else {
                surnameMap[command]++;
            }
        }
    }

    return 0;
}