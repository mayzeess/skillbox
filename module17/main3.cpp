#include <iostream>
using namespace std;

bool substr(const char* a, const char* b){

    for (int i = 0; *(a + i) != '\0'; i++){ // идем по первой строке
        if (*(a + i) == *(b)){ // пока не найдем первый символ совпадения
            int j = 0;
            while (*(b + j) != '\n' && *(a + i + j) != '\0'){ // идем по второй строке 
                if (!(*(a + i + j) == *(b + j))){ // если элементы не совпали, обрывваем цикл
                    break;
                }
                j++;
            }
            if (*(b + j) == '\0') return 1; // если дошли до конца, то есть подстрока
        }
    }

    return 0;
}

int main(){
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    cout << substr(a, b) << " " << substr(a, c);
    return 0;
}