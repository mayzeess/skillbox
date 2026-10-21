#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct coordinates {
    double x;
    double y;
};

void addAndSubtract(bool add){ // сложение и вычитание двух векторов 
    // (все тоже самое, чтобы не дублировать функцию, сделал одну, с булевой переменной)
    vector<coordinates> v;
    cout << "Input size vector: ";
    int size;
    cin >> size;

    for (int count = 0; count < 2; count++){ // всего 2 вектора, по очереди ввожу каждый из них
        double x, y;
        cout << "Input vector " << count + 1 << ".\n";
        for (int i = 0; i < size; i++){
            if (count == 0){ // сначала просто заполняем превый вектор
                cout << "Input el " << i + 1 << " (x, y): ";
                cin >> x >> y;
                v.push_back({x, y});
            }
            else { // потом сразу складываем 2 вектора
                cout << "Input el " << i + 1 << " (x, y): ";
                cin >> x >> y;
                if (add){ // работаем с одним вектором, сразу прибавляя (или отнимая) значения
                    v[i].x += x; 
                    v[i].y += y;
                }
                else {
                    v[i].x -= x;
                    v[i].y -= y;
                }
            }
        }
    }

    cout << endl << (add ? "Result addition of two vectors:\n\n" : "Result subtraction of two vectors:\n\n");
    for (int i = 0; i < v.size(); i++){
        cout << "(" <<  v[i].x << "; " << v[i].y << ")  ";
    }
    cout << endl;
}

void scale(){
    cout << "Input scalar: ";
    double scalar;
    cin >> scalar;

    vector<coordinates> v;
    cout << "Input size vector: ";
    int size;
    cin >> size;

    double x, y;
    for (int i = 0; i < size; i++){
        cout << "Input el " << i + 1 << " (x, y): ";
        cin >> x >> y;
        v.push_back({x * scalar, y * scalar}); // кладем в вектор элементы сразу умноженные
    }
    
    cout << endl;
    cout << "Result multiplication of a vector by a scalar:\n";
    for (int i = 0; i < v.size(); i++){
        cout << "(" <<  v[i].x << "; " << v[i].y << ")  ";
    }
    cout << endl;
}

void lengthVectorAndNormalize(bool opLength){ // одна функция для длины и нормализации вектора
    vector<coordinates> v;
    double x, y;
    cout << "Input start of a vector (x, y): ";
    cin >> x >> y;
    v.push_back({x, y});
    cout << "Input end of a vector (x, y): ";
    cin >> x >> y;
    v.push_back({x, y});

    double len = sqrtf(powf(v[1].x - v[0].x, 2) + powf(v[1].y - v[0].y, 2));

    if (opLength) {cout << endl << "Result finding the length of a vector: " << len << endl; return; }

    cout << "Result vector normalization: " << (v[1].x / len) << " " << (v[1].y / len) << endl;
}

int main(){
    string op;
    cout << "Commands:\nadd - addition of two vectors\nsubtract - subtraction of two vectors" << endl;
    cout << "scale - multiplication of a vector by a scalar\nlength - finding the length of a vector" << endl;
    cout << "normalize - vector normalization\nexit - exit program\n\n";
    
    while (true){
        cout << "Input operation: ";
        cin >> op;
        if (op == "add"){
            addAndSubtract(true);
        }
        else if (op == "subtract"){
            addAndSubtract(false);
        }
        else if (op == "scale"){
            scale();
        }
        else if (op == "length"){
            lengthVectorAndNormalize(true);
        }
        else if (op == "normalize"){
            lengthVectorAndNormalize(false);
        }
        else if (op == "exit"){
            cout << "Exit program\n";
            return 0;
        }
        else {
            cout << "Error command. Try again.\nInput exit to exit the program\n\n";
        }
    }

    return 0;
}