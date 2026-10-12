#include <iostream>
using namespace std;

void evenDigits(long long n, int &ans){
    if (n == 0) return;
    int temp = n % 10;
    if (temp % 2 == 0) ans++;

    evenDigits(n / 10, ans);
}

int main(){
    int ans = 0;
    evenDigits(9'223'372'036'854'775'806, ans);
    cout << ans;
    return 0;
}