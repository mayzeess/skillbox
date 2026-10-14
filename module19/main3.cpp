#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream dataFile;

    dataFile.open("D:\\skillbox\\module19\\dataFile.txt");

    string name, surname, date;
    double money, sum = 0, maxMoney = 0; // в данном примере можно было int, но деньги не всегда целое число. Решил использовать double

    string maxMoneyName, maxMoneySurname;

    while (!dataFile.eof()){
        dataFile >> name >> surname >> money >> date;
        if (money > maxMoney){
            maxMoney = money;
            maxMoneyName = name;
            maxMoneySurname = surname;
        }
        sum += money;
    }
    dataFile.close();
    
    cout << "Total paid: " << sum << endl;
    cout << maxMoneyName << " " << maxMoneySurname << " has the most money: " << maxMoney;
    
    return 0;
}