#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Branch{
    string name = "None";
    vector<Branch*> children;
    Branch* parent = nullptr;
    string elfName = "";

public:
    Branch(int treeDepth, int countChildren, string inName) : name(inName){ // передаем глубину дерева и кол-во детеей на каждой ветке
        for (int i = 0; i < countChildren; i++){
            if (treeDepth > 1) {
                if (treeDepth == 3) inName = "Big " + to_string(i);
                else if (treeDepth == 2)inName = "Middle " + to_string(i);
                children.push_back(new Branch(treeDepth - 1, rand() % 8 + 3, inName));
                children[i]->parent = this;
            }
        }
    }

    void populateElf(Branch* branch, int& countElf){ // функция заселения эльфов
        if (branch->parent != nullptr) {
            branch->elfName = "Elf #" + to_string(countElf + 1);
            countElf++;
        }
        for (int i = 0; i < branch->children.size(); i++){
            populateElf(branch->children[i], countElf);
        }
    }
    
    void printTree(int depth = 0){ // печатаем рекурсией дерево
        for (int i = 0; i < depth; i++) cout << "  ";
        cout << name << " - " << elfName << endl;
        for (int i = 0; i < children.size(); i++){
            children[i]->printTree(depth + 1);
        }
    }

    Branch* getTopBranch()
    {
        //Если это дерево
        if (parent == nullptr) return nullptr; 
        //Если это средняя ветка
        if (parent->parent == nullptr) return this;
        //Если это маленькая ветка
        return parent->getTopBranch();
    }

    Branch* searchElf(string name, Branch* branch){ // поиск эльфа, на какой ветке он живет
        if (branch->elfName == name) return branch;
        for (int i = 0; i < branch->children.size(); i++){
            Branch* found = searchElf(name, branch->children[i]);
            if (found != nullptr) return found;
        }
        return nullptr;
    }

    int searchCountNeighbors(Branch* branch){
        Branch* top = branch->getTopBranch();
        if (top != nullptr){
            int count = 0;
            for (int i = 0; i < top->children.size(); i++){
                if (top->children[i]->elfName != "") count++;
            }
            delete top;
            return count;
        }
        delete top;
        return 0;
    }
};

int main(){
    int countElf = 0; // счетчик эльфов, чтобы задать им неповторяющиеся имена
    vector<Branch*> elfVillage; // вектор деревьев эльфов. Вся дервня
    for (int i = 0; i < 2; i++){
        elfVillage.push_back(new Branch(3, rand() % 8 + 3, "Tree " + to_string(i + 1)));
        elfVillage[i]->populateElf(elfVillage[i], countElf); // заселяем всех эльфов
        elfVillage[i]->printTree();
    }
    cout << "Input 0 - exit program" << endl;
    while(true){
        cout << "Input name elf: ";
        string nameElf;
        getline(cin, nameElf);
        if (nameElf == "0") {
            for (int i = 0; i < elfVillage.size(); i++){ // очистка памяти перед завершением программы
                delete elfVillage[i];
            }
            cout << "exit program" << endl; break;
        }
        for (int i = 0; i < elfVillage.size(); i++){
            Branch* elf = nullptr;
            elf = elfVillage[i]->searchElf(nameElf, elfVillage[i]);
            if (elf != nullptr){
                cout << "Count neighbors " << nameElf << " : " << elfVillage[i]->searchCountNeighbors(elf) << endl;
                break;
            }
        }
    }
    return 0;
}