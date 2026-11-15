#include <iostream>
#include <vector>
using namespace std;

class Animal{
protected:
    string name;
    virtual void voice() = 0;
};

class Talent{ // абстарктный класс
public:
    virtual void ability() = 0;

    virtual ~Talent() = default;
};

class Swimming : virtual public Talent {
protected:
    virtual void ability(){
        cout << "Swimming!" << endl;
    }
};

class Dancing : virtual public Talent {
protected:
    virtual void ability(){
        cout << "Dancing!" << endl;
    }
};

class Counting : virtual public Talent {
protected:
    virtual void ability(){
        cout << "Counting!" << endl;
    }
};

class Dog : virtual public Animal{
    vector<Talent*> talent; // вектор талантов собаки
public:
    Dog(string inName){
        name = inName;
    };
    virtual void voice(){
        cout << "Bark!" << endl;
    }

    void run(){ // все собаки умеют бегать
        cout << "Run!" << endl;
    }

    void addTalent(Talent* ability){
        talent.push_back(ability);
    }

    void show_talents(){
        if (talent.empty()) {
            cout << name << " lacks talent" << endl;
            return;
        }
        cout << "This is " << name << " and it has some talents: " << endl;
        for (int i = 0; i < talent.size(); i++){
            cout << "\tIt can "; 
            talent[i]->ability();
        }
    }
};

class Cat : virtual public Animal{
public:
    Cat(string inName){
        name = inName;
    };

    virtual void voice(){
        cout << "Meow!" << endl;
    }    
};


int main(){
    Dog dog1("Steve");
    dog1.addTalent(new Dancing); // добавляем собаке талант 
    dog1.addTalent(new Swimming);
    dog1.show_talents();
    return 0;
}