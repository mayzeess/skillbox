#include <iostream>
#include <string>
using namespace std;

string isRelativeEqual(double current_speed, double change_speed, double delta = 0.01){

    current_speed += change_speed;

    if (current_speed < delta || current_speed > 150){
        current_speed < delta ? current_speed = 0 : current_speed = 150;
    }

    char speed_value[5];
    sprintf(speed_value, "%.1f", current_speed);

    return speed_value;
}

int main(){
    double speed = 0, change_speed;
    do {
        cout << "Speed delta: ";
        cin >> change_speed;
        speed = strtof(isRelativeEqual(speed, change_speed).c_str(), nullptr);
        cout << "Speed: " << speed << endl;
    } while (speed > 0);
    return 0;
}