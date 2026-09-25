#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool correctInput(string ipAdress) {
    //функция проверка на правильные символы и на количество цифр в числе (максимум 3)
    if (ipAdress[0] == '.' || ipAdress[ipAdress.length() - 1] == '.') return false;
    string number;
    for (int i = 0; ipAdress.length() > i; i++) {
        if (ipAdress[i] == '.' && ipAdress[i + 1] == '.') return false;
        if ((ipAdress[i] < '0' || ipAdress[i] > '9') && ipAdress[i] != '.') return false;
        
        if (ipAdress[i] == '.') number = "";
        else number += ipAdress[i];

        if (number.length() > 3) return false;
    }
    return true;
}


bool countNumber(string ipAdress){ // проверка что числа 4
    int count = 0;
    bool current = false;
    for (int i = 0; ipAdress.length() > i; i++){
        if (ipAdress[i] != '.' && !current){
            count++;
            current = true;
        } else if (ipAdress[i] == '.'){
            current = false;
        }
    }
    if (count == 4) return true;

    return false;
}

bool rightNumber(int number){ // проверка на то что число меньше 255
    return number > 255 ? false : true;
}


int get_number_ip(string ipAdress, int number){ // получаем число в формате int
    // второй аргумент - число по счету которое хотим получить (1, 2, 3, 4)
    string res = "";
    for (int i = 0 ; number > 0 && ipAdress.length() > i; i++) {
        if (ipAdress[i] != '.') res += ipAdress[i];
        else if (number - 1 > 0) {number--; res = "";}
        else number--;
    }

    if (res.length() > 1 && res[0] == '0') return 256; // возвращаем 256 если есть лишние нули
    // потом в проверке rightNumber будет false

    int x;
    if (res.length() == 3) {
        x = (res[0] - '0') * 100 + (res[1] - '0') * 10 + res[2] - '0';
    }
    else if (res.length() == 2) {
        x = (res[0] - '0') * 10 + res[1] - '0';
    } else {
        x = res[0] - '0';
    }

    return x;
}

bool examinationIpAdress(string ipAdress){
    if (correctInput(ipAdress) && countNumber(ipAdress)){
        for (int i = 1; i <= 4; i++){
            if (!rightNumber(get_number_ip(ipAdress, i))){
                return false;
            }
        }
        return true;
    }
    return false;
}


int main(){
    string ipAdress;
    cout << "Exit - 0\n";

    
    while(true){
        cout << "Input ip adress: ";
        getline(cin, ipAdress);
        cout << (examinationIpAdress(ipAdress) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}