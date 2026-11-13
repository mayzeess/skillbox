#include <iostream>
#include <thread>
#include <iomanip>
#include <vector>
#include <mutex>
#include <algorithm>
using namespace std;

vector<pair<double, string>> swimmers;
mutex swimmers_access;

void wait_for_swim(string name, double speed){
    double distance = 0;
    while (true){
        this_thread::sleep_for(chrono::seconds(1));
        distance += speed;
        swimmers_access.lock();
        if (distance >= 100){
            distance = 100;
            swimmers.push_back(make_pair(distance/speed, name));
            cout << name << " Finish, Time: " << fixed << setprecision(2) << distance/speed << endl;
            swimmers_access.unlock();
            break;
        }
        cout << name << " swimming: "  << fixed << setprecision(2) << distance << endl;
        swimmers_access.unlock();
    }
}

int main(){
    int countSwimmer = 6;
    string name[6];
    double speed[6];
    for (int i = 0; i < countSwimmer; i++){        
        cout << "Input name: ";
        cin >> name[i];
        cout << "Input speed: ";
        cin >> speed[i];
    }

    vector<thread> threads;
    for (int i = 0; i < countSwimmer; i++){
        threads.emplace_back(wait_for_swim, name[i], speed[i]);
    }
    
    for (int i = 0; i < countSwimmer; i++){
        threads[i].join();
    }

    cout << "Result:" << endl;
    sort(swimmers.begin(), swimmers.end()); // сортируем вектор
    for (int i = 0; i < swimmers.size(); i++){
        cout << i + 1 << ": " << swimmers[i].second << endl;
    }
    return 0;
}