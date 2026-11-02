#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class ConatactPhone{
    public:
        map<string, string> addressBook;
};

class Phone{
    ConatactPhone* contact = new ConatactPhone;

    void printCallOrSMS(bool call){
        if (call){
            cout << "CALL..." << endl;
        }
        else {
            cout << "Input sms\n";
            string sms;
            cin.ignore();
            getline(cin, sms);
            cout << "Message sent." << endl;
        }
    }

    public:
        void add(){
            cout << "Input number: +7";
            string number;
            cin >> number;
            number = "+7" + number;
            cout << "Input name: ";
            string name;
            cin >> name;
            contact->addressBook.insert({number, name});
        }

        void printContact(){
            map<string, string> oMap =  contact->addressBook;
            for(map<string, string>::iterator it = oMap.begin(); it != oMap.end(); it++){
                cout << it->first << " " << it->second << endl;
            }
        }

        void callAndSMS(bool call){ // если true - это звонок, false - sms
            cout << "Input name/number contact: ";
            string inputContact;
            cin >> inputContact;
            if (inputContact.length() > 2 && inputContact.substr(0, 2) == "+7"){ // проверил первые 2 символа, если начинаются на +7, значит пользователь ввел номер телефона
                if (contact->addressBook.find(inputContact) != contact->addressBook.end()){
                    cout << contact->addressBook.find(inputContact)->first << " " << contact->addressBook.find(inputContact)->second << endl;
                    printCallOrSMS(call);
                    return;
                }
                cout << "contact not found" << endl;
            }
            else {
                map<string, string> oMap = contact->addressBook;
                for (map<string, string>::iterator it = oMap.begin(); it != oMap.end(); it++){
                    if (it->second == inputContact){
                        cout << it->first << " " << it->second << endl;
                        printCallOrSMS(call);
                        return;
                    }
                }
                cout << "contact not found" << endl; // елси не нашли контакт, то выводим сообщение, что контакт не найден
            }
        }

        void deleteContact(){
            delete contact;
            contact = nullptr;
        }
};

void printCommand(){
    cout << "add - create new contact" << endl;
    cout << "call - make a call" << endl;
    cout << "sms - send message" << endl;
    cout << "exit - exit program" << endl;
}

int main(){
    printCommand();
    string command;
    Phone* phone = new Phone;
    while(true){
        cout << "Input command: ";
        cin >> command;
        if (command == "add"){
            phone->add();
        }
        else if (command == "call"){
            phone->callAndSMS(true);
        }
        else if (command == "sms"){
            phone->callAndSMS(false);
        }
        else if (command == "exit"){
            cout << "Exit program" << endl;
            phone->deleteContact();
            delete phone;
            phone = nullptr;
            return 0;
        }
        else {
            cout << "Error command" << endl;
            printCommand();
        }
    }
    
    
    return 0;
}