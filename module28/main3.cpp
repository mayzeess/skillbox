#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
using namespace std;

bool workKitchen = true; // переменная, которая завершает прошрамму при 10 заказах
mutex workKitchen_access;

mutex cout_access; // мьютекс для вывода информации
mutex kithen_access; // мьютекс для приготовления заказа, пока один заказ готовится, другой ждет

vector<string> ready; // вектор готовых блюд
mutex ready_access;

void wait_for_preparations(string name, int timepPreparations);

void wait_for_order(int dishIndex, int timepPreparations){ // рандомный выбор блюда и запуск его готовки
    string menu[] = {"pizza", "soup", "steak", "salad", "sushi"};

    cout_access.lock();
    cout << "Order placed " << menu[dishIndex] << endl;
    cout_access.unlock();

    thread preparations(wait_for_preparations, menu[dishIndex], timepPreparations);
    preparations.detach();
}

void wait_for_preparations(string name, int timepPreparations){ // ожидание готовки, пока заказ готовится (5-15 сек)
    kithen_access.lock(); // пробуем заблокировать мьютекс для готовки
    cout_access.lock();
    cout << "Preparing a dish " << name << endl;
    cout_access.unlock();

    this_thread::sleep_for(chrono::seconds(timepPreparations));

    ready_access.lock();
    ready.push_back(name);
    ready_access.unlock();

    cout_access.lock();
    cout << "Order preparation " << name << endl;
    cout_access.unlock();

    kithen_access.unlock();    
}

void wait_for_courier(){ // ожидание курьера, каждые 30 сек
    int countDelivery = 0;
    while(countDelivery < 10){
        this_thread::sleep_for(chrono::seconds(30)); // ждем 30 сек
        ready_access.lock();
        int count = ready.size();
        ready.clear(); // очищаем вектор, курьер забрал все заказы
        ready_access.unlock();
        if (count > 0){
            cout_access.lock();
            cout << "Courier delivered " << count << " the orders" << endl;
            cout_access.unlock();
            countDelivery += count;
        }
    }
    workKitchen_access.lock();
    workKitchen = false;
    workKitchen_access.unlock();
}

int main(){
    srand(time(nullptr));
    thread coureir(wait_for_courier); // отдельно запускаю поток курьера
    while(true){
        // задаю рандомные значения в main, чтобы они всегда были разные
        int dishIndex = rand() % 5; // рандомное блюдо, которое заказали
        int timeOrder = rand() % 6 + 5;
        int timepPreparations = rand() % 11 + 5;

        workKitchen_access.lock();
        if (!workKitchen) break; // если работа закончена, выходим из программы
        workKitchen_access.unlock();

        this_thread::sleep_for(chrono::seconds(timeOrder));  // функция ожиджания заказа (5-10 сек)
        thread work(wait_for_order, dishIndex, timepPreparations);
        work.detach();
    }
    coureir.join();
    return 0;
}