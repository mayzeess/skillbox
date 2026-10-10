#include <iostream>
using namespace std;

void reverse(int* a){
    for (int i = 9; i >= 0; i--){
        cout << *(a + i) << " ";
    }
}

int main(){
    int a[10] = {5, 4, 76, 4, 3, 4, 3, 3, 20, 22};

    reverse(a);
    return 0;
}