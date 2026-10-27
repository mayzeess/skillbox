#include <iostream>
#define AUTUMN
using namespace std;



int main(){
    #ifdef SPRING
    cout << "SPRING";
    #endif

    #ifdef SUMMER
    cout << "SUMMER";
    #endif

    #ifdef AUTUMN 
    cout << "AUTUMN ";
    #endif

    #ifdef WINTER 
    cout << "WINTER ";
    #endif

    #if !defined(SPRING) && !defined(SUMMER) && !defined(AUTUMN) && !defined(WINTER)
    cout << "error";
    #endif

    return 0;
}