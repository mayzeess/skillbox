#include <iostream>
#include <vector>
#include "cpu.h"
#include "keyboard.h"
#include "ram.h"
#include "disk.h"
#include "gpu.h"
using namespace std;

void printListCommand(){
    cout << "List commmand:\nsum - calculate the sum of the numbers from the RAM\n";
    cout << "save - save to a file\nload - load from file\ninput - enter 8 numbers from the keyboard\n";
    cout << "display - display on screen\nexit - exit the program" << endl;
}

int main(){
    string command;
    printListCommand();
    cout << endl;
    while (true){
        cout << "Input command: ";
        cin >> command;
        if (command == "sum"){
            compute();
        }
        else if (command == "save"){
            save();
        }
        else if (command == "load"){
            load();
        }
        else if (command == "input"){
            inputBuffer();
        }
        else if (command == "display"){
            printBuffer();
        }
        else if (command == "exit"){
            cout << "Exi program" << endl;
            return 0;
        }
        else {
            cout << "Error command" << endl;
            printListCommand();
        }
    }

    return 0;
}