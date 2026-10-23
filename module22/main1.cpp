#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    map<string, string> telephoneDirectory;
    cout << "1 - add tel and surname\n2 - surname surname over the phone\n3 - phone over the surname\n0 - exit program" << endl;
    int command;
    while (true){
        cout << "Input command: ";
        cin >> command;
        string phone;
        string suranme;
        if (command == 1){
            cout << "Input phone and suranme: ";
            cin >> phone >> suranme;
            telephoneDirectory.insert({phone, suranme});
            cout << "contact add\n";
        }
        else if (command == 2){
            cout << "Input number: ";
            cin >> phone;
            cout << telephoneDirectory[phone] << endl;
        }
        else if (command == 3){
            cout << "Input surname: ";
            cin >> suranme;
            for (map<string, string>::iterator it = telephoneDirectory.begin(); it != telephoneDirectory.end(); it++){
                if (it->second == suranme){
                    cout << it->first << endl;
                }
            }
        }
        else if (command == 0){
            cout << "Exit program\n";
            return 0;
        }
        else {
            cout << "erroe operation\nTry again:";
        }
    }
    return 0;
}