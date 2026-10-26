#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main(){
    map<string, string> numberToSurname;
    map<string, vector<string>> surnameToNumber;
    cout << "1 - add tel and surname\n2 - surname over the phone\n3 - phone over the surname\n0 - exit program" << endl;
    int command;
    
    while (true){
        cout << "Input command: ";
        cin >> command;
        string phone;
        string suranme;
        vector<string> vecPhone;
        if (command == 1){
            cout << "Input phone and suranme: ";
            cin >> phone >> suranme;
            numberToSurname.insert({phone, suranme});
            
            if (surnameToNumber.find(suranme) != surnameToNumber.end()){ // проверка, если такая фамилия уже есть
                vecPhone = surnameToNumber.find(suranme)->second;
                vecPhone.push_back(phone);
                surnameToNumber.find(suranme)->second = vecPhone;
            }
            else {
                vecPhone.push_back(phone);
                surnameToNumber.insert({suranme, vecPhone});
            }
            cout << "contact add\n";
        }
        else if (command == 2){
            cout << "Input number: ";
            cin >> phone;
            if (numberToSurname.find(phone) != numberToSurname.end()){
                cout << numberToSurname[phone] << endl;
            }
            else {
                cout << "There is no such data.\n";
            }
            
        }
        else if (command == 3){
            cout << "Input surname: ";
            cin >> suranme;
            if (surnameToNumber.find(suranme) != surnameToNumber.end()){
                map<string, vector<string>>::iterator it = surnameToNumber.find(suranme);
                for (int i = 0; i < it->second.size(); i++){
                    cout << it->second[i] << endl;
                }
            }
            else{
                cout << "There is no such data.\n";
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