#include <iostream>
#include "tools.h"
#include <cfloat>
#include <cmath>
using namespace std;

void inputAndPrintCoordinate(string command){
    cout << "Command: " << command << endl;
    cout << "Input point: ";
    double x, y;
    cin >> x >> y;
    cout << (command == "hemostat" ? "A clamp is applied at the point " : "tweezers used in point ") << x << " " << y << endl;
}

void input2Coordinate(twoDimCoordinate& coordinate){ // функция ввода координат
    cout << "Input the first point: ";
    cin >> coordinate.x1 >> coordinate.y1;
    cout << "Input the second point: ";
    cin >> coordinate.x2 >> coordinate.y2;
}

void print2Coordinate(twoDimCoordinate coordinate, string command){ // вывод координат с командой
    cout << "Command: " << command << endl;    
    cout << (command == "suture" ? "a suture has been placed: " : "an incision has been made: ") << endl;
    cout << "Point 1: " << coordinate.x1 << " " << coordinate.y1 << endl;
    cout << "Point 2: " << coordinate.x2 << " " << coordinate.y2 << endl;
}

bool examinationCoordinate(twoDimCoordinate& coordinate1, twoDimCoordinate& coordinate2){
    if (abs(coordinate1.x1 - coordinate2.x1) >= DBL_EPSILON || abs(coordinate1.y1 - coordinate2.y1) >= DBL_EPSILON){
        return false;
    }

    if (abs(coordinate1.x2 - coordinate2.x2) >= DBL_EPSILON || abs(coordinate1.y2 - coordinate2.y2) >= DBL_EPSILON){
        return false;
    }

    return true;
}