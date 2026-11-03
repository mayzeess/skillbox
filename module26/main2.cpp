#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class ConatactPhone{
    map<string, string> addressBook;

    public: 
        void add(string number, string name){
            addressBook.insert({number, name});
            cout << "Contact add" << endl;
        }

        string searchContact(string contact){ // функция поиска контакта по номеру или имени и вывода его
            if (contact.length() > 2 && contact.substr(0, 2) == "+7"){ // проверил первые 2 символа, если начинаются на +7, значит пользователь ввел номер телефона
                if (addressBook.find(contact) != addressBook.end()){
                    cout << addressBook.find(contact)->first << " " << addressBook.find(contact)->second << endl;
                    return addressBook.find(contact)->first;
                }
                return contact;
            }
            else {
                for (map<string, string>::iterator it = addressBook.begin(); it != addressBook.end(); it++){
                    if (it->second == contact){
                        cout << it->first << " " << it->second << endl;
                        return it->first;
                    }
                }
            }
            return ""; // пустая строка, если введено имя, которого нету в контактах
        }
};

class Phone{
    ConatactPhone* contactPhone = new ConatactPhone;

    void callPhone(string contact){
        if (contactPhone->searchContact(contact) != ""){
            cout << "CALL..." << endl;
        }
        else{
            cout << "contact not found" << endl;
        }
    }

    void smsPhone(string contact){
        if (contactPhone->searchContact(contact) != ""){
            cout << " SMS sent" << endl;
        }
        else{
            cout << "contact not found" << endl;
        }                
    }

    void addContact(string number, string name){
        contactPhone->add(number, name);
    }

    public:
        void call(string contact){
            callPhone(contact);
        }

        void add(string number, string name){
            addContact(number, name);
        }

        void sms(string contact, string sms){ // с сообщением ничего не делается, так как это симуляция. Но я передаю его в класс телефона
            smsPhone(contact);
        }

        void deleteConatactPhone(){
            delete contactPhone;
            contactPhone = nullptr;
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
            cout << "Input number: +7";
            string number, name;
            cin >> number;
            number = "+7" + number;
            cout << "Input name: ";
            cin >> name;
            phone->add(number, name);
        }
        else if (command == "call"){
            cout << "Input name/number contact: ";
            string inputContact;
            cin >> inputContact;
            phone->call(inputContact);
        }
        else if (command == "sms"){
            string inputContact, sms;
            cout << "Input contact: ";
            cin >> inputContact;
            cout << "Input sms: ";
            cin.ignore();
            getline(cin, sms);
            phone->sms(inputContact, sms);
        }
        else if (command == "exit"){
            cout << "Exit program" << endl;
            phone->deleteConatactPhone();
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