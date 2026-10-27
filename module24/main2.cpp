#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
using namespace std;

void sortVec(vector<pair<string, tm>>& listFriends){ // функция сортировки нашего вектора с датами методом пузырька.
    // даты рождения размещены по возрастанию не учитывая год рождения. (только месяц и день)
    pair<string, tm> oPair;
    for (int i = 0; i < listFriends.size(); i++){
        for (int j = 0; j < listFriends.size() - 1 - i; j++){
            if ((listFriends[j + 1].second.tm_mon < listFriends[j].second.tm_mon) || (listFriends[j + 1].second.tm_mon == listFriends[j].second.tm_mon && listFriends[j + 1].second.tm_mday < listFriends[j].second.tm_mday)){
                oPair = listFriends[j + 1];
                listFriends[j + 1] = listFriends[j];
                listFriends[j] = oPair;
            }
        }
    }
}

int main(){
    pair<string, tm> oPair;
    vector<pair<string, tm>> listFriends;

    cout << "Input 'end' to finish the input process\n";
    while (true){
        cout << "Input name friend: ";
        string name;
        cin >> name;
        if (name == "end"){
            break;
        }
        cout << "Type input date of birth - dd.mm.yyyy\n";
        cout << "Input date of birth " << name << ": ";

        oPair.first = name;
        time_t t = time(nullptr);
        tm local = *localtime(&t);
        cin >> get_time(&local, "%d.%m.%Y");
        oPair.second = local;
        listFriends.push_back(oPair);
        cout << "Birthday add: " << name << " " << put_time(&local, "%d.%m.%Y") << endl;
    }

    time_t now = time(nullptr);
    tm local_now = *localtime(&now);

    sortVec(listFriends); // отсортировали вектор, по дню рождению в году, не учитывая дату.

    for (int i = 0; i < listFriends.size(); i++){
        if (local_now.tm_mon == listFriends[i].second.tm_mon && local_now.tm_mday == listFriends[i].second.tm_mday){
            cout << "Today is a birthday: " << listFriends[i].first << " " << put_time(&listFriends[i].second, "%m/%d") << endl;
        }
        else if ((local_now.tm_mon < listFriends[i].second.tm_mon) || (local_now.tm_mon == listFriends[i].second.tm_mon && local_now.tm_mday < listFriends[i].second.tm_mday)){
            cout << "the next birthday " << listFriends[i].first << " " << put_time(&listFriends[i].second, "%m/%d") << endl;
            break;
        }
    }

    return 0;
}