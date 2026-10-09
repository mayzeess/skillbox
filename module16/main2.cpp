#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    string number1, number2;
    cout << "Input first part number: ";
    cin >> number1;
    cout << "Input second part number: ";
    cin >> number2;

    number1 += "." + number2;
    cout << number1 << "\n";
    double value = strtod(number1.c_str(), nullptr);

    cout << setprecision(number1.length() - 1) << value;
    return 0;
}