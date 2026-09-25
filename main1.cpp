#include <iostream>
#include <string>
using namespace std;

string encrypt_caesar(string text, int shift){
    string result;
    while (shift >= 26) shift -= 26;
    for (int i = 0; i < text.length(); i++){
        if (text[i] < 65 || text[i] > 90 && text[i] < 97 || text[i] > 122){
            result += text[i];
            continue;
        }
        if ((text[i] <= 90 && text[i] + shift > 90) || text[i] + shift > 122) text[i] -= 26;
        result += text[i] + shift; 
    }

    return result;
}
// написал программу сразу сравнивая числа из таблицы ASCII, хотя можно было и сомволы
// например text[i] < 'A' || text[i] > 'Z'

int main(){
    string text;
    int shift;
    cout << "Input text: ";
    getline(cin, text);
    cout << "Input shift: ";
    cin >> shift;

    while (shift < 0){
        cout << "Try again. Shift >= 0.\nInput shift: ";
        cin >> shift;
    }

    cout << "Result: " << encrypt_caesar(text, shift) << endl;
    return 0;
}