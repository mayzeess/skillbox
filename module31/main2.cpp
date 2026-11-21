#include <iostream>
using namespace std;

class Toy{
    string name;
public:
    Toy(string inName) : name(inName){}
    Toy() : Toy("Some toy"){}

    string getName(){
        return name;
    }

    ~Toy() {
        cout << "Toy " << name << " was dropped " << endl;
    }
};

class shared_ptr_toy{
    int* count; // указатель на счетчик
    Toy* toy; // указатель на объект
public:
    int use_count() const{ // возвращает количество ссылок на объект Toy
        if (count == nullptr) return 0;
        return *count;
    }

    void reset(){
        if (count == nullptr) return;
        if (*count > 1){
            (*count)--;
            count = nullptr;
            toy = nullptr;
            return;
        }
        delete toy;
        delete count;
        count = nullptr;
        toy = nullptr;
    }

    Toy* get() const{
        return toy;
    }

    shared_ptr_toy(const shared_ptr_toy& other){ // конструктор копирования
        if (other.count == nullptr){
            count = nullptr;
            toy = nullptr;
            return;
        }
        toy = other.toy; // скопируем указатель на объект
        count = other.count; // скопируем указатель на счетчик
        (*count)++; // увеличим счетчик на 1
    }

    shared_ptr_toy(string inName){ // новый объект, создается новый объект Toy и счетчик 
        toy = new Toy(inName); // создатся новый объект Toy
        count = new int(1);
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other){ // оператор присваивания
        if (this == &other) return *this; // если присваиваем оббъект самому себее
        reset(); // уменьшаем счетчик и удаляем объект, если счетчик равен 0

        if (other.count == nullptr){
            count = nullptr;
            toy = nullptr;
            return *this;
        }
        toy = other.toy; // скопируем указатель на объект
        count = other.count; // скопируем указатель на счетчик
        (*count)++; // увеличим счетчик на 1
        return *this;
    }

    shared_ptr_toy() : count(nullptr), toy(nullptr){}

    string getToyName() const{
        if (toy == nullptr) return "Nothing";
        return toy->getName();
    }
    
    ~shared_ptr_toy(){
        reset();
    }

};

shared_ptr_toy make_shared_toy(string inNameToy){
    return shared_ptr_toy(inNameToy);
}

int main() {
   shared_ptr_toy toy_01 = make_shared_toy("ball");
   shared_ptr_toy toy_02(toy_01);
   shared_ptr_toy toy_03("duck");
   std::cout << "=================================================" << std::endl;
   std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
             << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
             << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
   std::cout << "=================================================" << std::endl;
   toy_02 = toy_03;
   std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
             << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
             << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
   std::cout << "=================================================" << std::endl;
   toy_01.reset();
   std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
             << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
             << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
   std::cout << "=================================================" << std::endl;
   return 0;
}