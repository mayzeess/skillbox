#include <iostream>
#include <sstream>
#include <iostream>
using namespace std;

enum switches // состояние переключателей
{
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16
};

bool changeState(int oldState, int state, switches sensor);

void printState(int state, int oldState, int time){ // печатаем состояния

    cout << "TIME: " << time << ":00\n";

    if (changeState(oldState, state, HEATERS)){
        cout << ((state & HEATERS) ? "HEATERS: ON!" : "HEATERS: OFF!") << endl;
    }
    if (changeState(oldState, state, LIGHTS_INSIDE)){
        cout << ((state & LIGHTS_INSIDE) ? "LIGHTS_INSIDE: ON!" : "LIGHTS_INSIDE: OFF!") << endl;
    }
    if (changeState(oldState, state, LIGHTS_OUTSIDE)){
        cout << ((state & LIGHTS_OUTSIDE) ? "LIGHTS_OUTSIDE: ON!" : "LIGHTS_OUTSIDE: OFF!") << endl;
    }
    if (changeState(oldState, state, WATER_PIPE_HEATING)){
        cout << ((state & WATER_PIPE_HEATING) ? "WATER_PIPE_HEATING: ON!" : "WATER_PIPE_HEATING: OFF!") << endl;
    }
    if (changeState(oldState, state, CONDITIONER)){
        cout << ((state & CONDITIONER) ? "CONDITIONER: ON!" : "CONDITIONER: OFF!") << endl;
    }

    if (state & LIGHTS_INSIDE){
        if (time > 15 && time < 21){
            cout << "Color temperature: " << 5000 - ((time - 15) * 460) << "K";
        }
        else {
            cout << "Color temperature: 5000K"; 
        }
        cout << "\n\n";
    }
}

bool changeState(int oldState, int state, switches sensor){ // проверка, было ли изменино состояние
    if ((oldState & sensor) == (state & sensor)){
        return false;
    }
    return true;
}

int sensors(int state, string data, int time){ // настраиваем наши данные
    int oldState = state;
    if (time > 23){
        time -= 24;
    }

    int t_inside, t_outside;
    string movement, lights;
    stringstream temp_string(data);

    temp_string >> t_inside >> t_outside >> movement >> lights;
    if (movement != "no" && movement != "yes" || lights != "on" && lights != "off"){
        cout << "Error input\n";
        return 0;
    }

    if (t_outside < 0){
        state |= WATER_PIPE_HEATING;
    }

    if (t_outside > 5){
        state &= ~WATER_PIPE_HEATING;
    }

    if (time > 16 && time < 5 && movement == "yes"){
        state |= LIGHTS_OUTSIDE;
    }

    else {
        state &=  ~LIGHTS_OUTSIDE;
    }

    if (t_inside < 22){
        state |= HEATERS;
    }

    if (t_inside > 24){
        state &= ~HEATERS;
    }

    if (t_inside > 29){
        state |= CONDITIONER;
    }

    if (t_inside < 26){
        state &=  ~CONDITIONER;
    }

    if (lights == "on"){
        state |= LIGHTS_INSIDE;
    }
    else {
        state &= ~LIGHTS_INSIDE;
    }

    printState(state, oldState, time);

    return state;
}

int main(){
    string data;
    int state = 0;

    for (int i = 0; i < 48; i++){
        cout << "Temperature inside, temperature outside, movement, lights:\n";
        getline(cin, data);
        state = sensors(state, data, i);
    }

    return 0;
}