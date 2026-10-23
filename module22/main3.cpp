#include <iostream>
#include <map>
#include <string>
using namespace std;

bool anagram(string word1, string word2){
    if (word1.length() != word2.length()) return false;

    map<char, int> words; // ключ - символ строки(слова), значение - количество таких символов в строке(слове)
    for (int i = 0; word1[i] != '\0'; i++){ // добавляю в элемент символ, и кол-во. У первого слова +, у второго -
        words[word1[i]]++;
        words[word2[i]]--;
    }

    for (map<char, int>::iterator it = words.begin(); it != words.end(); it++){
        if(it->second != 0) return false; // если это анаграмма, все элементы по ключам должны быть 0
    }

    return true;
}

int main(){
    cout << "0 - exit\n";
    string word1, word2;
    while (true)
    {
        cout << "Input two words for checking an anagram: ";
        cin >> word1 >> word2;
        if (word1 == "0" || word2 == "0"){ cout << "exit program"; return 0; }
        cout << (anagram(word1, word2) ? "These are anagrams\n" : "These are not anagrams\n");
    }

    return 0;
}