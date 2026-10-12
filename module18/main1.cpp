#include <iostream>
#include <vector>
using namespace std;

void swapvec(vector<int>& v, int* arr){
    for (int i = 0; i < 4; i++){
        int temp = arr[i];
        arr[i] = v[i];
        v[i] = temp;
    }
    cout << endl;
}

int main(){
    vector<int> v = {1, 2, 3, 4};
    int arr[] = {2, 4, 6, 8};
    swapvec(v, arr);


    for (int i = 0; i < 4; i++){
        cout << v[i] << " ";
    }

    cout << "\n";
    for (int i = 0; i < 4; i++){
        cout << arr[i] << " ";
    }

    return 0;
}