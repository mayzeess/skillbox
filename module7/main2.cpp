#include <iostream>
using namespace std;

int main(){
    int water, milk;
    cout << "Введите количество воды в мл: ";
    cin >> water;
    cout << "Введите количество молока в мл: ";
    cin >> milk;
    int latte = 0, americano = 0;
    for(;(water >= 30 && milk >= 270) || water >= 300;){
        int x;
        cout << "Выберите напиток (1 — американо, 2 — латте): ";
        cin >> x;
        if (x == 1){
            if (water >= 300){
                americano++;
                water -= 300;
                cout << "Ваш напиток готов.\n***Отчёт***\n";
                cout << "Ингредиентов осталось:\n\tВода: " << water << "\n\t" << "Молоко: " << milk << "\n";
            } else {
                cout << "Не хватает ингредиентов\n";
            }
            
        } else if (x == 2){
            if (water >= 30 && milk >= 270){
                latte++;
                water -= 30;
                milk -=270;
                cout << "Ваш напиток готов.\n***Отчёт***\n";
                cout << "Ингредиентов осталось:\n\tВода: " << water << "\t" << "Молоко: " << milk << "\n";
            } else {
                cout << "Не хватает ингредиентов\n";
            }
            
        }
    }

    cout << "Кружек американо приготовлено: " << americano << "\n";
    cout << "Кружек латте приготовлено: " << latte << "\n";
    return 0;
}