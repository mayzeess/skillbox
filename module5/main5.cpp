#include <iostream>
using namespace std;

int main(){
    int a, b, c, m, n, k;
    cout << "Напишите размер первой коробки, 3 числа: ";
    cin >> a >> b >> c;
    cout << "Напишите размер второй коробки, 3 числа: ";
    cin >> m >> n >> k;
    if((a < m && b < n && c < k) || (a < m && b < k && c < n)
    || (a < n && b < m && c < k) || (a < n && b < k && c < m)
    || (a < k && b < m && c < n) || (a < k && b < n && c < m)){
        cout << "поместится";
    } else {
        cout << "не поместится";
    }
    return 0;
}