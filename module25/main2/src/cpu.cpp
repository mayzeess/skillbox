#include <iostream>
#include <vector>
#include "cpu.h"
using namespace std;

void compute(vector<int> v){
    if (v.size() < 8){
        cout << "insufficient data" << endl;
        return;
    }
    
    int sum = 0;
    for (int i = 0; i < v.size(); i++){
        sum += v[i];
    }

    cout << "Sum: " << sum << endl;
}