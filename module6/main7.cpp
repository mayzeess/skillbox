#include <iostream>
using namespace std;

int module(int x){
    if (x < 0) return x*-1;
    return x;
}

int main(){
    cout << "Сокращение дроби\n";
    int numerator, denominator;
    bool flag = false;
    bool data = false;
    do{
        int maxDivider;
        if (!data){
            cout << "Введите числитель: ";
            cin >> numerator;
            cout << "Введите знаменатель: ";
            cin >> denominator;
            if (denominator < 0){
                cout << "При вводе отрицательных чисел в выводе должен быть только один ведущий минус.\n";
                continue;
            }
            if (module(numerator) <= denominator){
                maxDivider = module(numerator);
            } else {
                maxDivider = denominator;
            }
            data = true;
        }
        if ((numerator % maxDivider == 0 && denominator % maxDivider == 0) || maxDivider == 1){
            numerator /= maxDivider;
            denominator /= maxDivider;
            flag = true;
        } else if(maxDivider == numerator || maxDivider == denominator) maxDivider /=2 ; // чтобы ускорить работу программы. 
        //если число не подходит для сокращения, то мы сразу поделим его на 2, так как это ближайший делитель
        else maxDivider--;
    } while(!flag);

    cout << "Результат: " << numerator << "/" << denominator;
    return 0;
}