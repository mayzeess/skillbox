#include <iostream>
using namespace std;

int main(){
    int width = 15, height = 20; //можно поменять размер поля
    int x = width /2;
    int y = height /2;
    cout << "Программа управления робота-разведчика поверхности Марса.\n";
    cout << "Используйте w/a/s/d для перемещения\n";
    for(;;){
        cout << "[Программа]: Марсоход находится на позиции " << x << ", " << y << ", введите команду: ";
        string direction;
        cin >> direction;
        if (direction == "w"){
            cout << "[Оператор] W\n";
            if (y < height) y++;    
        } else if (direction == "s"){
            cout << "[Оператор] S\n";
            if (y > 1) y--;
        } else if (direction == "a"){
            cout << "[Оператор] A\n";
            if (x > 1) x--;
        } else if (direction == "d"){
            cout << "[Оператор] D\n";
            if (x < width) x++;
        } else if (direction != "w" && direction != "s" && direction != "a" && direction != "d"){
            cout << "Неправильный ввод, используйте только w/a/s/d\n";
        }
    }
    return 0;
}