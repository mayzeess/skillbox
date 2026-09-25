#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool symbols(char x, int half) {
    string symbols;
    //елси это не буква, то проверяем остальные символы которые могут встретиться
    // в первой или второй полоаине
    if (half == 1){
        symbols = ".!#$%&'*+-/=?^_`{|}~-0123456789";
    } else {
        symbols = ".0123456789-";
    }

    for (int i = 0; i < symbols.length(); i++) {
        if (x == symbols[i]) return true;
    }
    return false;
}

bool exainationSymbol(char symbol, string text){
    // проверяем на подряд идуцщие 2 точки и на количество знаков '@'
    int count = 0;
    for (int i = 0; text.length() > i; i++){
        if (text[i] == '.' && text[i + 1] == '.') return false;
        if(text[i] == symbol) count++;
    }
    if (count == 1) return true;

    return false;
}

bool examinationMain(string email, bool half) {
    // передаем строку и порловину, которую проверяем (0 - первая или 1 - вторая)
    if (email[0] == '.') return false;
    int i = 0;
    while (email.length() > i) {
        //работаем до символа '@', или до конца строки
        if (email[i] == '@') break;
        if (email[i] < 'A' || email[i] > 'Z' && email[i] < 'a' || email[i] > 'z') {
            if (half == 0 && !symbols(email[i], 1)) {
                return false;
            }
            else if (half == 1  && !symbols(email[i], 2)) {
                return false;
            }
        }
        i++;
    }

    // проверка на количество символов в 1 и 2 половине
    if ((i < 1 || i > 64) && half == 1) { return false; }
    else if ((i < 1 || i > 63) && half == 2) { return false; }

    return true;
}

int main() {
    string email;
    cout << "0 - exit\n";
    while (true) {
        cout << "Input email adress: ";
        getline(cin, email);
        if (email == "0") break;
        string reversed = email; // доп переменную, присваиваем нашей почте, только перевернутую
        //получается мы точно также проверяем, только задом наперед
        reverse(reversed.begin(), reversed.end());
        cout << (exainationSymbol('@', email) && examinationMain(email, 0) && examinationMain(reversed, 1) ? "Yes\n" : "No\n");
    }

    cout << "Exit" << endl;
    return 0;
}