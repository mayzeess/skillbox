#include <iostream>
using namespace std;

int main(){
    string number;
    cout << "Input number: ";
    cin >> number;
    bool separator = false, good = true, thereNumber = false;

    if (number[0] != '-' && number[0] != '.' && (number[0] < 48 || number[0] > 57)){
        cout << "No\n";
        return 0;
    }

    if(number[0] == '.'){
        separator = true;
    }

    for(int i = 1; number.length() > i && good; i++){
        if ((number[i] > 57 || number[i] < 48) && number[i] != '.' || number[i] == '.' && separator){
            good = false;
        }
        if(number[i] == '.' && !separator){
            separator = true;
        }
        if (number[i] <= 57 && number[i] >= 48 && !thereNumber){
            thereNumber = true;
        }
    }

    cout << (good && thereNumber ? "Yes\n" : "No\n");
    return 0;
}