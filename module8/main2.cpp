#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float health, resistance, power, damage;
    cout << " Введите количество здоровья орка: ";
    cin >> health;
    cout << " Введите сопротивляемость магии орка: ";
    cin >> resistance;
    if (health > 1 || health < 0 || resistance > 1 || resistance < 0){
        cout << "Неверные данные. Все показатели в пределах от 0 до 1";
        return 0;
    }
    for (int i = 1; health > 0; i++){
        cout << " Введите мощность огненного шара: ";
        cin >> power;
        if (power < 0 || power > 1) {cout << "Урон должен быть в перелах от 0 до 1\n"; continue;}
        cout << "Удар номер " << i << "\n";
        damage = power - (power * resistance);
        cout << "Урон " << power << ", сопротевляемость " << resistance 
        << " по орку будет нанесено " << damage << " урона.\n";
        health -= damage;
        if (health < 0) health = 0;
        cout << "Оставшейся здоровье " << health << "\n";
    }

    return 0;
}