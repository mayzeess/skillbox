#include <iostream>
#include <fstream>
using namespace std;



int main(){
    int count = 0;
    string word;
    cout << "Input word: ";
    cin >> word;

    ifstream words;
    words.open("D:\\skillbox\\module19\\words.txt");

    while(!words.eof()){
        string currentWord;
        words >> currentWord;
        if (currentWord == word){
            count++;
        }
    }

    cout << "Count words: " << count;

    words.close();

    return 0;
}