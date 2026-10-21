#include <iostream>
#include <vector>
using namespace std;

enum structures_type { // перечисления сооружения
    house, garage, barn, bathhouse
}; // дом гараж сарай баня

enum room_type{ // типы комнат на этаже
    bedroom,
    kitchen,
    bathroom,
    children,
    living
};

struct room{
    room_type room;
    int square;
};

struct floor_house{ // структура этажа
    vector<room> room; // комнаты на данном этаже
    int height; // высота потолка на этаже
};

struct plotOfLandStructures{ // структура сооружений (само сооружение, его площадь, этаж)
    structures_type structures;
    vector<floor_house> floor; // этаж (в нем кол-во комнат)
    int square;
    bool stovepipe;
};

struct plotOfLand{ // главная структура участка
    int number; // уникальный номер
    vector<plotOfLandStructures> structures; // сооружения (само сооружение и его площадь)
};

void InputStructures(plotOfLand& land, int& count);
void InputFloor(plotOfLandStructures& pols, int& count);
void InputRoom(floor_house& fh, int& count);

void InputPlotOfLand(vector<plotOfLand>& land, int& count){ // вводим количество участков
    for (int i = 0; i < count; i++){
        plotOfLand pof;
        cout << "Input number plot of land: ";
        cin >> pof.number;
        int count_structures;
        cout << "Input count structures: ";
        cin >> count_structures;
        InputStructures(pof, count_structures);
        land.push_back(pof);
    }
}

void InputStructures(plotOfLand& land, int& count){ // вводим кол-во домов
    for (int i = 0; i < count; i++){
        int n;
        cout << "Input structures (0 - house, 1 - garage, 2 - barn, 3 - bathhouse): ";
        cin >> n;
        plotOfLandStructures pols;
        if (n == structures_type::house) { pols.structures = house; }
        else if (n == structures_type::garage) { pols.structures = garage; }
        else if (n == structures_type::barn) { pols.structures = barn; }
        else if (n == structures_type::bathhouse) { pols.structures = bathhouse; }
        cout << "Input square: ";
        cin >> pols.square;
        if (n == structures_type::house || n == structures_type::bathhouse) {
            cout << "Input stovepipe (0 - no/ 1 - yes): ";
            cin >> pols.stovepipe;
        } else {
            pols.stovepipe = 0;
        }

        if (n == structures_type::house){
            int count_floor;
            cout << "Input count floor: ";
            cin >> count_floor;
            InputFloor(pols, count_floor);
        }
        land.structures.push_back(pols);
    }
    
}

void InputFloor(plotOfLandStructures& pols, int& count){ // вводим кол-во этажей
    for (int i = 0; i < count; i++){
        floor_house fh;
        cout << "Input height floor: ";
        cin >> fh.height;
        int count_room;
        
        cout << "Input count room: ";
        cin >> count_room;
        InputRoom(fh, count_room);
        pols.floor.push_back(fh);
    }
}

void InputRoom(floor_house& fh, int& count){
    for (int i = 0; i < count; i++){
        cout << "Input type room (0 - bedroom, 1 - kitchen, 2 - bathroom, 3 - children, 4 - living): ";
        int n;
        cin >> n;
        room rm;
        if (n == room_type::bedroom) { rm.room = bedroom; }
        else if (n == room_type::kitchen) { rm.room = kitchen; }
        else if (n == room_type::bathroom) { rm.room = bathroom; }
        else if (n == room_type::children) { rm.room = children; }
        else if (n == room_type::living) { rm.room = living; }
        cout << "Input square room: ";
        cin >> rm.square;
        fh.room.push_back(rm);
    }
}

int main(){
    int count;
    cout << "Input count plot of land: ";
    cin >> count;
    vector<plotOfLand> land;
    InputPlotOfLand(land, count);
    return 0;
}