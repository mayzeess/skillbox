#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <map>
#include <vector>
using namespace std;

struct film{
    string name;
    string country;
    string date;
    string studio;
    string scenario;
    string director;
    string producer;
    string leadingRole;
    string actor1;
    string actor2;
    string actor3;
};

// задание 1
void task1(){
    ofstream file("file.json");
    nlohmann::json dict = {
        {"name", "Odyssey"},
        {"country", "USA"},
        {"date", "July 6, 2026"},
        {"studio", "Universal Pictures"},
        {"scenario", "Christopher Nolan"},
        {"director", "Christopher Nolan"},
        {"producer", "Christopher Nolan"},
        {"leading role", "Matt Damon"},
        {"actor 1", "Tom Holland"},
        {"actor 2", "Anne Hathaway"},
        {"actor 3", "Robert Pattinson"}
    };
    file << dict.dump(4); // отступ в 4 пробела для карсивой записи
    file.close();
}

// задание 2
void searchActor(string nameActor, vector<film>& films){ // функция для поиска фильмов по актеру
    ifstream file("file2.json");
    nlohmann::json dict;
    file >> dict;
    bool found = false;
    for (int i = 0; i < films.size(); i++){
        if (nameActor == films[i].leadingRole || nameActor == films[i].actor1 || nameActor == films[i].actor2 || nameActor == films[i].actor3){
            found = true;
            cout << "Film: " << films[i].name << endl;
            cout << "Role: ";
            cout << (nameActor == films[i].leadingRole ? "Leading role" : (nameActor == films[i].actor1 ? "Actor 1" : (nameActor == films[i].actor2 ? "Actor 2" : "Actor 3"))) << endl << endl;
        }
    }
    if (!found){
        cout << "Actor not found" << endl;
    }
    file.close();
}


void task2(){
    vector<film> films;
    // данные фильмов
    film film1 = {
        "Odyssey",
        "USA", 
        "July 6, 2026", 
        "Universal Pictures", 
        "Christopher Nolan", 
        "Christopher Nolan", 
        "Christopher Nolan", 
        "Matt Damon", 
        "Tom Holland", 
        "Anne Hathaway", 
        "Robert Pattinson" 
    };
    films.push_back(film1);
    film film2 = {
        "The Hateful Eight",
        "USA", 
        "December 7, 2015", 
        "The Weinstein Company LLC", 
        "Quentin Tarantino", 
        "Quentin Tarantino",
        "Richard N. Gladstein",
        "Kurt Russell", 
        "Samuel L. Jackson", 
        "Jennifer Jason Leigh", 
        "Walton Goggins" 
    };
    films.push_back(film2);
    film film3 = {
        "Resident Evil",
        "USA, Germany, France", 
        "September 16, 2026", 
        "Columbia Pictures", 
        "Zach Cregger", 
        "Zach Cregger", 
        "Zach Cregger", 
        "Austin Abrams", 
        "Zach Cherry", 
        "Kali Reis", 
        "Paul Walter Hauser"
    };
    films.push_back(film3);
    film film4 = {
        "Spider-Man: Brand New Day",
        "USA, Canada, UK, Germany", 
        "July 27, 2026",
        "Columbia Pictures", 
        "Destin Daniel Cretton", 
        "Chris McKenna", 
        "Kevin Feige", 
        "Tom Holland", 
        "Zendaya", 
        "Sadie Sink", 
        "Jacob Batalon" 
    };
    films.push_back(film4);
    film film5 = {
        "Dirty Money",
        "UK, USA", 
        "May 21, 2026", 
        "Black Bear",
        "Guy Ritchie", 
        "Guy Ritchie", 
        "John Friedberg", 
        "Jake Gyllenhaal", 
        "Henry Cavill", 
        "Eiza González", 
        "Rosamund Pike" 
    };
    films.push_back(film5);

    map<string, string> infoFilms;
    nlohmann::json dict;
    for (int i = 0; i < films.size(); i++){
        infoFilms["country"] = films[i].country;
        infoFilms["date"] = films[i].date;
        infoFilms["studio"] = films[i].studio;
        infoFilms["scenario"] = films[i].scenario;
        infoFilms["director"] = films[i].director;
        infoFilms["producer"] = films[i].producer;
        infoFilms["leading role"] = films[i].leadingRole;
        infoFilms["actor 1"] = films[i].actor1;
        infoFilms["actor 2"] = films[i].actor2;
        infoFilms["actor 3"] = films[i].actor3;
        dict[films[i].name] = infoFilms;
    }

    ofstream file("file2.json");
    file << dict.dump(4) << endl;
    file.close();

    cout << " 0 - exit program" << endl;
    while(true){
        cout << "Enter the actor's name: ";
        string nameActor;
        getline(cin, nameActor);
        if (nameActor == "0") break;
        searchActor(nameActor, films);
    }
}

int main(){
    task1();
    task2();
    return 0;
}