#include <iostream>
#include <sstream>
using namespace std;

double calculator(string example){
    double a, b;
    char op;
    stringstream temp_stream(example);
    temp_stream >> a >> op >> b;

    if (op == '+'){
        a += b;
    }
    else if (op == '-'){
        a -= b;
    }
    else if (op == '/'){
        a /= b;
    }
    else if(op == '*'){
        a *= b;
    }
    else{
        cout << "Operation error";
        return 0;
    }
    return a;
}

int main(){
    cout << "Input example: ";
    string example;
    cin >> example;

    cout << calculator(example);

    return 0;
}