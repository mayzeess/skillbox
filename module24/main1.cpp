#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

// решил вынести конец задачи в отдельную фунуцию, чтобы вызывать ее при вызове begin, когда одна задача уже идет
void endTask(bool &current_task, time_t t_start, pair<string, time_t>& oPair, vector<pair<string, time_t>>& task){
    if (current_task){
        time_t t_end = time(nullptr);
        tm locale = *localtime(&t_end);
        double res = difftime(t_end, t_start);
        time_t f = (t_start + (time_t)res) - t_start;
        //time_t f = res; // можно и так
        oPair.second = f;
        cout << "End task " << oPair.first << endl << asctime(&locale);
        task.push_back(oPair);
    }
    else{
        cout << "There is no task at the moment" << endl;
    }
    current_task = false;
}

int main(){
    string command;
    time_t t_start;
    
    pair<string, time_t> oPair; // пара, для добавления в вектор
    vector<pair<string, time_t>> task;
    
    bool current_task = false; // булева переменная для отслеживания, есть ли сейчас задача
    
    while (true){
        cout << "Input command: ";
        cin >> command;
        if (command == "begin"){
            if (current_task){
                endTask(current_task, t_start, oPair, task);
            }
            cout << "Name task: ";
            string name;
            cin >> name;
            t_start = time(nullptr);
            tm locale = *localtime(&t_start);
            cout << "Begin task " << name << endl << asctime(&locale);
            oPair.first = name;
            current_task = true;
        }
        else if (command == "end"){
            endTask(current_task, t_start, oPair, task);
        }
        else if (command == "status"){
            for (int i = 0; i < task.size(); i++){
                tm* local = localtime(&task[i].second);
                local->tm_hour -= 4;
                cout << "Task: " << task[i].first << " Time: " << put_time(local, "%H:%M:%S") << endl; // разница часовой формат, так как
            }
            if (current_task){
                cout << "Current task: " << oPair.first << endl;
            }
        }
        else if(command == "exit"){
            cout << "exit program" << endl;
            return 0;
        }
        else {
            cout << "error input. Try again" << endl;
        }
    }
    
    return 0;
}