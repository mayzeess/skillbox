#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

class Worker{
    string name = "";
    bool free = 0; // 0 работник свободен, 1 - занят
    char typeTask = '0';
public:
    Worker(string inName = ""): name(inName){}

    void getName(){
        cout << "\t" << name << " - ";
        if (free){
            cout << "Performs task " << typeTask << endl;
        }
        else {
            cout << "Free" << endl;
        }
    }

    bool workersFree(){ // проверка на то, занят ли уже работник
        return (free ? true : false);
    }

    void createTaskWorkers(){ // создается задача для работников
        free = true;
        int task = rand() % 3; // ранлдомная задача для работника
        switch (task){
            case 0:
                typeTask = 'A';
                break;
            case 1:
                typeTask = 'B';
                break;
            case 2:
                typeTask = 'C';
                break;
        }
    }
};

class Team{
    string name = "";
    int numberTeam = 0;
    int countWorker = 0;
public:
    vector<Worker> workers;
    Team(string inName, int inNumberTeam, int inCountWorker, int inAllWorkers) : name(inName), numberTeam(inNumberTeam), countWorker(inCountWorker){
        for (int i = 0; i < countWorker; i++){
            workers.emplace_back("Worker " + to_string(inAllWorkers + i + 1));
        }
    }

    void getTeam(){
        cout << name << endl;
        for (int i = 0; i < countWorker; i++){
            workers[i].getName();
        }
    }

    void createTaskTeam(int inTaskCount){
        for (int i = 0; i < countWorker; i++){
            if (!workers[i].workersFree() && inTaskCount > 0){ // если работник свободен и еще есть задачи
                workers[i].createTaskWorkers();
                inTaskCount--;
            }
            else{
                continue;
            }
        }
    }

    int getFreeWorkersTeam(){ // получаем количество рабочих, которые уже свободны
        int count = 0;
        for (int i = 0; i < countWorker; i++){
            if (!workers[i].workersFree()) count++;
        }
        return count;
    }
};

class Manager{
    int numberTeam = 0;
    string name = "";
    int countWorker = 0;
    int taskCount = 0;
    int AllWorkers = 0;
public:
    Manager(string inName, int inNumberTeam, int inCountWorker, int inAllWorkers) : name(inName), numberTeam(inNumberTeam), countWorker(inCountWorker), AllWorkers(inAllWorkers) {
        //tasksCount = rand() % (team->workers.size() + 1);
    }
    
    Team* team = new Team("Team " + to_string(numberTeam + 1), numberTeam, countWorker, AllWorkers);
    void getManager(){
        cout << name << " - ";
        team->getTeam();
    }

    void createTaskManager(int inTask){ // создание задачи мнеджера для команды в зависимости от числа главы компании
        int freeWorkers = team->getFreeWorkersTeam();
        if (freeWorkers == 0) {
            taskCount = 0;
            return;
        }
        srand(numberTeam + 1);
        taskCount = rand() % freeWorkers + 1; // количество задач для команды
        if (taskCount > freeWorkers) taskCount = freeWorkers;
        team->createTaskTeam(taskCount);
    }

    ~Manager(){
        delete team;
    }
};

class HeadCompany{
    int task = 0;
    int countTeam = 0;
    Manager** managers = nullptr;
    int AllWorkers = 0; // счетчик всех рабочих, чтобы в новой команде начинать не с 1, а продолжить счетчик
public:
    void inputTask(int inTask){
        //task = inTask;
        for (int i = 0; i < countTeam; i++){
            managers[i]->createTaskManager(inTask);
        }
    }

    HeadCompany(int inCountTeam = 0) : countTeam(inCountTeam){
        managers = new Manager*[countTeam]{};
    }

    void createManager(int inNumberTeam, int inCountWorkers){
        managers[inNumberTeam] = new Manager("Manager " + to_string(inNumberTeam + 1), inNumberTeam, inCountWorkers, AllWorkers);
        AllWorkers += inCountWorkers;
    }

    void printInfo(){
        for (int i = 0; i < countTeam; i++){
            managers[i]->getManager();
        }
    }

    ~HeadCompany() {
        for (int i = 0; i < countTeam; i++){ // очищаем память если больше нету рабочих
            delete managers[i];
        }
        delete[] managers;
    }
    
    bool employment(){ // функция для определения, есть ли свободные рабочие в компании
        for (int i = 0; i < countTeam; i++){
            if (managers[i]->team->getFreeWorkersTeam() > 0) return true;
        }
        return false;
    }

};

int main(){
    cout << "Input count team: ";
    int countTeam = rand() % 10 + 3; // рандомное число команд
    cout << countTeam << endl;
    HeadCompany* headCompany = new HeadCompany(countTeam);
    for (int i = 0; i < countTeam; i++){
        int countWorker = rand() % 10 + 4;
        cout << "Input count worker for team " << i + 1 << ": ";
        cout << countWorker << endl;
        headCompany->createManager(i, countWorker);
    }
    while(headCompany->employment()){
        headCompany->printInfo();
        int task;
        cout << "Input task (number): ";
        cin >> task;
        headCompany->inputTask(task);
    }
    cout << "All workers are busy." << endl;
    delete headCompany;
    headCompany = nullptr;
    return 0;
}