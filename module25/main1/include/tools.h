#pragma once
#include <string>
using namespace std;

struct twoDimCoordinate{
    double x1;
    double y1;
    double x2;
    double y2;
};

void input2Coordinate(twoDimCoordinate& coordinate);
void print2Coordinate(twoDimCoordinate coordinate, string command);
void inputAndPrintCoordinate(string command);
bool examinationCoordinate(twoDimCoordinate& coordinate1, twoDimCoordinate& coordinate2);