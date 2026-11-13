#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex cout_access;
mutex travel_access;

void wait_for_start(string name, int timeTravel){
    string command = "";

    cout_access.lock();
    cout << "Train " << name << " set off for the train station." << endl; // отправился
    cout_access.unlock();

    this_thread::sleep_for(chrono::seconds(timeTravel));
    if (!travel_access.try_lock()){ // пробуем заблокировать мьютекс, если не получилось то ждем очередь
        cout_access.lock();
        cout << "Train " << name << " waiting for their turn" << endl; // ждет очереди
        cout_access.unlock();
        travel_access.lock();
    }
    
    cout_access.lock();
    cout << endl << "Train " << name << " arrived at the train station" << endl; 
    cout_access.unlock();

    while (command != "depart"){
        cout_access.lock();
        cout << "Input command - depart:" << endl;
        cout_access.unlock();
        cin >> command;
    }
    travel_access.unlock();

    cout_access.lock();
    cout << "Train " << name << " departed from the station" << endl; // уехал со станции
    cout_access.unlock();
}

int main(){
    vector<thread> threads;

    string name[3] = {"A", "B", "C"};
    int timeTravel[3];

    for (int i = 0; i < 3; i++){
        cout << "Input travel time for train " << name[i] << ": ";
        cin >> timeTravel[i];
    }

    for(int i = 0; i < 3; i++){
        threads.emplace_back(wait_for_start, name[i], timeTravel[i]);
    }

    for (int i = 0; i < threads.size(); i++){
        threads[i].join();
    }
    return 0;
}