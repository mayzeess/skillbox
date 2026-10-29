#include <iostream>
#include <vector>
#include "cpu.h"
#include "keyboard.h"
#include "ram.h" // только команды из данной функции не использутся. 
// по заданию они как бы совпадают с командами в файле cpu и keyboard. 
// может я что-то не так понял. Сами функции реализованы но не используются.
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
    vector<int> bufer;
    while (true){
        cout << "Input command: ";
        cin >> command;
        if (command == "sum"){
            compute(bufer);
        }
        else if (command == "save"){
            if (!bufer.empty()){
                save(bufer);
            }
        }
        else if (command == "load"){
            load(bufer);
        }
        else if (command == "input"){
            inputBuffer(bufer);
        }
        else if (command == "display"){
            read(bufer);
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