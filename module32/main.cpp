#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"
#include <map>
#include <vector>
using namespace std;

struct actor{ // структура актеров
    string actor;
    string role;
};

struct film{
    string name;
    string country;
    string date;
    string studio;
    string scenario;
    string director;
    string producer;
    vector<actor> actors;
};

// задание 1
void task1(){
    film odyssey;
    odyssey.name = "Odyssey";
    odyssey.country = "USA";
    odyssey.date = "July 6, 2026";
    odyssey.studio = "Universal Pictures";
    odyssey.scenario = "Christopher Nolan";
    odyssey.director = "Christopher Nolan";
    odyssey.producer = "Christopher Nolan";
    odyssey.actors.push_back({"Matt Damon", "Leading role"});
    odyssey.actors.push_back({"Tom Holland", "Actor 1"});
    odyssey.actors.push_back({"Anne Hathaway", "Actor 2"});
    odyssey.actors.push_back({"Robert Pattinson", "Actor 3"});

    ofstream file("file.json");
    nlohmann::json dict;
    dict[odyssey.name]["country"] = odyssey.country;
    dict[odyssey.name]["date"] = odyssey.date;
    dict[odyssey.name]["studio"] = odyssey.studio;
    dict[odyssey.name]["scenario"] = odyssey.scenario;
    dict[odyssey.name]["director"] = odyssey.director;
    dict[odyssey.name]["producer"] = odyssey.producer;
    dict[odyssey.name]["actors"] = nlohmann::json::array();
    for (int i = 0; i < odyssey.actors.size(); i++){
        dict[odyssey.name]["actors"][i]["actor"] = odyssey.actors[i].actor;
        dict[odyssey.name]["actors"][i]["role"] = odyssey.actors[i].role;
    }
    file << dict.dump(4); // отступ в 4 пробела для карсивой записи
    file.close();
}

// задание 2
void searchActor(string nameActor){ // функция для поиска фильмов по актеру
    ifstream file("file2.json");
    nlohmann::json dict;
    file >> dict;
    bool found = false;
    // for (int i = 0; i < films.size(); i++){
    //     for (int j = 0; j < films[i].actors.size(); j++){
    //         if (films[i].actors[j].actor == nameActor){
    //             cout << "\nFilm: " << films[i].name << endl;
    //             cout << "Role: " << films[i].actors[j].role << endl;
    //             found = true;
    //         }
    //     }
    // }
    for (auto& [filmName, filmInfo] : dict.items()){ // объект json для поиска
        for (auto& actorInfo : filmInfo["actors"]){
            if (actorInfo["actor"] == nameActor){
                cout << "\nFilm: " << filmName << endl;
                cout << "Role: " << actorInfo["role"] << endl;
                found = true;
            }
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
        {
            {"Matt Damon", "Leading role"}, 
            {"Tom Holland", "Actor 1"}, 
            {"Anne Hathaway", "Actor 2"}, 
            {"Robert Pattinson", "Actor 3"}
        }
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
        {
            {"Kurt Russell", "Leading role"},
            {"Samuel L. Jackson", "Actor 1"},
            {"Jennifer Jason Leigh", "Actor 2"},
            {"Walton Goggins", "Actor 3"}
        }
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
        {
            {"Austin Abrams", "Leading role"}, 
            {"Zach Cherry", "Actor 1"}, 
            {"Kali Reis", "Actor 2"}, 
            {"Paul Walter Hauser", "Actor 3"}
        }
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
        {
            {"Tom Holland", "Spider-Man"}, 
            {"Zendaya", "MJ"}, 
            {"Sadie Sink", "Actor 2"}, 
            {"Jacob Batalon", "Actor 3"}
        }
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
        {
            {"Jake Gyllenhaal", "Leading role"}, 
            {"Henry Cavill", "Actor 1"}, 
            {"Eiza González", "Actor 2"}, 
            {"Rosamund Pike", "Actor 3"}
        }
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
        dict[films[i].name] = infoFilms;
        dict[films[i].name]["actors"] = nlohmann::json::array();
        for (int j = 0; j < films[i].actors.size(); j++){
            dict[films[i].name]["actors"][j]["actor"] = films[i].actors[j].actor;
            dict[films[i].name]["actors"][j]["role"] = films[i].actors[j].role;
        }
        
    }

    ofstream file("file2.json");
    file << dict.dump(4) << endl;
    file.close();

    cout << " 0 - exit program" << endl;
    while(true){
        cout << "\nEnter the actor's name: ";
        string nameActor;
        getline(cin, nameActor);
        if (nameActor == "0") break;
        searchActor(nameActor);
    }
}

int main(){
    task1();
    task2();
    return 0;
}