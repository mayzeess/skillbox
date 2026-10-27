#include <iostream>
using namespace std;

int main(){
    int birthdayDay, birthdayMonth, birthdayYear;
    int todayDay, todayMonth, todayYear;
    cout << "Введите день рождения покупателя через пробел (день, месяц, год): ";
    cin >> birthdayDay >> birthdayMonth >> birthdayYear;
    cout << "Введите сегодняшнюю дату через пробел (день, месяц, год): ";
    cin >> todayDay >> todayMonth >> todayYear;
    if ((todayYear - birthdayYear > 18) 
    || (todayYear - birthdayYear == 18 && todayMonth > birthdayMonth)
    || (todayYear - birthdayYear == 18 && todayMonth == birthdayMonth && todayDay > birthdayDay)){
        cout << "можно";
    } else {
        cout << "Нельзя";
    }
    return 0;
}