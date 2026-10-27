#include <iostream>
#include <string>
using namespace std;


int main() {
    string text;
    cout << "Input text: ";
    getline(cin, text);

    int count = 0, sizeWord = 0;
    bool word = true;
    for (int i = 0; text.length() > i; i+=sizeWord + 1) {
        word = false;
        sizeWord = 0;
        for (int j = 0; text[i + j] != ' ' && text.length() > i + j; j++) {
            word = true;
            sizeWord++;
        }
        if (word) {
            count++;
        }
    }
    cout << "Words found: " << count;
    return 0;
}