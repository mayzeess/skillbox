#include <iostream>
using namespace std;

void menu(string day[], int dayWeek){
    if (dayWeek > 0 && dayWeek < 8){
        cout << "Меню сегодня ";
    }
    if (dayWeek == 1){
        cout << "(" << day[0] << ")\n";
        cout << "Гороховый суп\n";
        cout << "Салат «Цезарь» с креветками\n";
        cout << "Куриная ножка с пюре\n";
        cout << "Морс\n";
    } else if (dayWeek == 2){
        cout << "(" << day[1] << ")\n";
        cout << "Борщ\n";
        cout << "Салат крабовый\n";
        cout << "Котлета с макаронами\n";
        cout << "Чай\n";
    } else if (dayWeek == 3){
        cout << "(" << day[2] << ")\n";
        cout << "Суп Щи\n";
        cout << "Салат оливье\n";
        cout << "Рис с сосисками\n";
        cout << "Какао\n";
    } else if (dayWeek == 4){
        cout << "(" << day[3] << ")\n";
        cout << "Суп Уха\n";
        cout << "Салат свекольный\n";
        cout << "Стейк\n";
        cout << "Кофе\n";
    } else if (dayWeek == 5){
        cout << "(" << day[4] << ")\n";
        cout << "Суп Лапша\n";
        cout << "Салат селедка под шубой\n";
        cout << "картошка с котлетой\n";
        cout << "Лимонад\n";
    } else if (dayWeek == 6){
        cout << "(" << day[5] << ")\n";
        cout << "Грибной суп\n";
        cout << "Салат «Цезарь» с курицей\n";
        cout << "Шашлык\n";
        cout << "Сок яблочный\n";
    } else if (dayWeek == 7){
        cout << "(" << day[6] << ")\n";
        cout << "Суп перловый\n";
        cout << "Салат капустный\n";
        cout << "Люля-Кебаб\n";
        cout << "Сок апельсиновый\n";
    } else {
        cout << "Такого дня недели нет.";
    }
}

int main(){
    string days[] = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    cout << "Меню ресторана\n";
    int dayWeek;
    cout << "Введите день недели: ";
    cin >> dayWeek;
    menu(days, dayWeek);
    return 0;
}