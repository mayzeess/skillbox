#include <iostream>
#include <algorithm>
using namespace std;

void alg(int a, int b, int c){
    int minVal = min({a, b, c});
    int maxVal = max({a, b, c});
    
    cout << "Минимальное: " << minVal << "\n";
    cout << "Максимальное: " << maxVal << "\n";
    cout << "Разница: " << maxVal - minVal << "\n";
}

void anotherMax(int a, int b, int c){
    if (a >= b && a >= c){
        cout << "Наиболше число: " << a << "\n";
    } else if (b >= a && b >= c) {
        cout << "Наибольшее число: " << b << "\n";
    } else {
        cout << "Наибольшее число: " << c << "\n";
    }
}

void anotherMin(int a, int b, int c){
    if (a <= b && a <= c){
        cout << "Наименьшее число: " << a << "\n";
    } else if (b <= a && b <= c) {
        cout << "Наименьшее число: " << b << "\n";
    } else {
        cout << "Наименьшее число: " << c << "\n";
    }
}

int main(){
    cout << "Зарплата\n";
    int salary1, salary2, salary3;
    cout << "Введите зарплату первого сотрудника: ";
    cin >> salary1;
    cout << "Введите зарплату второго сотрудника: ";
    cin >> salary2;
    cout << "Введите зарплату третьего сотрудника: ";
    cin >> salary3;
    if (salary1 <= 0 || salary2 <= 0 || salary3 <= 0){
        cout << "Зарплата у всех должна быть больше 0\n";
        return 0;
    }
    cout << "-----Считаем-----\n";
    if (salary1 >= salary2){
        if (salary1 >= salary3){
            cout << "Самая высокая зарплата в отделе: " << salary1 << " рублей\n";
            if (salary2 >= salary3){
                cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << salary1 - salary3 << " рублей\n";
            } else {
                cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << salary1 - salary2 << " рублей\n";
            }
        } else {
            cout << "Самая высокая зарплата в отделе: " << salary3 << " рублей\n";
            if (salary1 >= salary2){
                cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << salary3 - salary2 << " рублей\n";
            } else {
                cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << salary3 - salary1 << " рублей\n";
            }
        }
    }
    else if (salary2 >= salary1){
        if (salary2 >= salary3){
            cout << "Самая высокая зарплата в отделе: " << salary2 << " рублей\n";
            if (salary1 >= salary3){
                cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << salary2 - salary3 << " рублей\n";
            } else {
                cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << salary2 - salary1 << " рублей\n";
            }
        } else {
            cout << "Самая высокая зарплата в отделе: " << salary3 << " рублей\n";
            if (salary1 >= salary2){
                cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << salary3 - salary2 << " рублей\n";
            } else {
                cout << "Разница между самой высокой и самой низкой зарплатой в отделе: " << salary3 - salary1 << " рублей\n";
            }
        }
    }
    cout << "Средняя зарплата в отделе: " << (salary1 + salary2 + salary3) / 3 << " рублей\n";

    cout << "-------------------------------\nВторой способ\n";
    alg(salary1, salary2, salary3);
    cout << "-------------------------------\nТретий способ\n";
    anotherMax(salary1, salary2, salary3);
    anotherMin(salary1, salary2, salary3);
    return 0;
}