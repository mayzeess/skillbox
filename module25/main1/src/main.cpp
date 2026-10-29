#include <iostream>
#include "tools.h"
#include <cfloat>
using namespace std;


int main(){
    twoDimCoordinate scalpel;
    twoDimCoordinate suture;
    while (true){
        cout << "Command:  scalpel" << endl;
        input2Coordinate(scalpel);
        print2Coordinate(scalpel, "scalpel");
        inputAndPrintCoordinate("hemostat");
        inputAndPrintCoordinate("tweezers");
        cout << "Command:  suture" << endl;
        input2Coordinate(suture);
        print2Coordinate(suture, "suture");
        if (examinationCoordinate(scalpel, suture)){
            cout << "The operation is complete" << endl;
            break;
        }
    }

    return 0;
}