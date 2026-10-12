#include <iostream>
using namespace std;

int jumpRabbit(int n, int k = 3){
    if (n < 0) return 0;
    if (n == 0) return 1;
    int sum = 0;

    for (int i = 1; i <= k; i++){
        sum += jumpRabbit(n - i, k);
    }

    return sum;
}

int main(){
    cout << jumpRabbit(3, 2);
    return 0;
}