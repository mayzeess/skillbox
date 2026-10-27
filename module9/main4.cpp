#include <iostream>
using namespace std;

string goodInput(string text) {
    bool good = false;
    do {
        bool valid = false;
        cin >> text;
        if (text.length() != 4) {
            cout << "Try again. The number is 4 digits long.\nInput number: ";
            continue;
        }
        for (int i = 0; text.length() > i; i++) {
            if (text[i] < 48 || text[i] > 57) {
                cout << "Try again. Enter only numbers.\nInput number: ";
                break;
            }
            valid = true;
        }
        if (valid) good = true;
    } while (!good);

    return text;
}

void solution(){ // доп функция которая не используется. (Начальное решение)
    // первое почти правильное решение. 
    // проблема возникла с данными 1222, 2234.
    // проблема в том, что 3 и 4 числа, совпадают с первым. И оба считают как ++cow,
    // но ++cow, доолжно повториться 1 раз
    string number, result;
    cout << "Input first number: ";
    number = goodInput(number);

    int bull = 0, cow = 0;

    while (bull != 4) {
        bull = 0, cow = 0;
        cout << "Input second number: ";
        result = goodInput(result);
        for (int i = 0; number.length() > i; i++) {
            if (number[i] == result[i]) { 
                bull++;
                continue; 
            }
            for (int j = 0; result.length() > j; j++) {
                if (number[i] == result[j] && number[j] != result[j]) { 
                    cow++;
                    break;
                }
            }
        }
        cout << "Bull: " << bull << " Cow: " << cow << "\n";
    }
}

int main() {
    // тут рабочее решение.
    string number, result;
    cout << "Input first number: ";
    number = goodInput(number);

    int bull = 0, cow = 0;

    while (bull != 4) {
        bull = 0, cow = 0;
        bool numberUsed[] = { 0, 0, 0, 0 }; // не придумал ничего лучше, чем завести
        // массив булевой переменной, где каждое значение помечается - использовано или нет
        // это поможет ++cow, делать 1 раз, когда идут подряд одинаковые числа. 
        // так как была проблема с примером 1222, 2234 
        cout << "Input second number: ";
        result = goodInput(result);
        for (int i = 0; number.length() > i; i++) {
            if (number[i] == result[i]) {
                numberUsed[i] = 1;
                bull++;
                continue;
            }
            for (int j = 0; result.length() > j; j++) {
                if (number[i] == result[j] && number[j] != result[j] && !numberUsed[j]) {
                    numberUsed[j] = 1;
                    cow++;
                    break;
                }
            }
        }
        cout << "Bull: " << bull << " Cow: " << cow << "\n";
    }
    return 0;
}