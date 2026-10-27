#include <iostream>
using namespace std;

int main(){
    for(int y = 0; y < 24; y++){
        for(int x = 0; x < 50; x++){
            if (x == 25 && y == 0) cout << "^";
            else if (y == 12 && x == 25) cout << "+";
            else if (x == 49 && y == 12) cout << ">";
            else if (x == 25) cout << "|";
            else if (y == 12) cout << "-";
            else cout << " ";
        }
        cout << "\n";
    }
    return 0;
}