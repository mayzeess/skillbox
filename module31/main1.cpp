#include <iostream>
#include <memory>
using namespace std;

class Toy{
    string name;
public:
    Toy(string inName) : name(inName){}
    Toy() : Toy("Some toy"){} // если не будем передавать аргумент имени в игрушку, то она создатся с именем Some toy

    string getName(){
        return name;
    }

    ~Toy() {
        cout << "Toy " << name << " was dropped " << endl;
    }
};

class Dog{
    string name;
    shared_ptr<Toy> toy;
public:
    Dog(string inName) : name(inName) {}
    Dog() : Dog("Name Dog") {}
    void getToy(const shared_ptr<Toy>& oth){
        if (oth == toy){
            cout << "I already have this toy" << endl;
            return;
        }
        if (oth.use_count() > 1){ // если игрушка находится у другой собаки
            cout << "Another dog is playing with this toy" << endl;
            return;
        }
        toy = oth;
        cout << name << " picked up a toy" << endl;
    }

    void dropToy(){
        if (toy == nullptr){
            cout << "Nothing to drop" << endl;
            return;
        }
        toy.reset();
        cout << name << " threw the toy" << endl;
    }
};

int main(){
    shared_ptr<Toy> ball = make_shared<Toy>("Ball");
    Dog dog1("Sharik");
    Dog dog2("Pushok");
    Dog dog3("Drozhok");

    dog2.getToy(ball);
    dog3.getToy(ball);
    dog1.dropToy();
    dog2.dropToy();
    dog3.getToy(ball);
    return 0;
}