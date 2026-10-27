#include <iostream>
using namespace std;

int main(){
    cout << "Кукушка\n";
    cout << "Введите, который час: ";
    int time;
    cin >> time;
    while(time != 0){
        if (time > 23 || time < 0){
            cout << "Столько времени быть не может, попробуйте еще раз\nВведите, который час: ";
            cin >> time;
        } else {
            cout << "Ку-ку!\n";
            time--;
        }
        
    }
    return 0;
}