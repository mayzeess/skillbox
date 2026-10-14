#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream sector;
    int numberSector[13];

    sector.open("D:\\skillbox\\module19\\sectorNumber.txt");
    if (!sector.is_open()){ cout << "Error"; return 0; }
    for (int i = 0; i < 13; i++){ // записываем в массив из файла
        sector >> numberSector[i];
    }
    sector.close();


    int pointsPlayer = 0, pointsSpectators = 0; // счетчик очков
    int currentSector = 0; // текущий сектор

    while(pointsSpectators < 6 && pointsPlayer < 6){ 
        int offset;
        cout << "Input offset sector: ";
        cin >> offset;
        offset += currentSector; // смещение сектора

        while (offset >= 13){ // если смещение выходит за пределы, убаляем его
            offset -= 13;
        }
        currentSector = *(numberSector + offset);

        while (currentSector == 0){ // если текущий сектор уже был (равен 0), то переходим на следущий
            offset++;
            currentSector = *(numberSector + offset);
            if (offset >= 13){
                offset -= 13;
            }
        }

        numberSector[currentSector - 1] = 0; // зануляем текущий сектор

        char numSec[2];
        sprintf(numSec, "%d", currentSector); // переводим текущий сектор в число

        ifstream questionSector;
        string sectorPathQuestion = "D:\\skillbox\\module19\\sectors\\question"; 
        string fileExtension = ".txt";
        sectorPathQuestion += numSec;
        sectorPathQuestion += fileExtension; // создаем путь к файлу - вопросу

        questionSector.open(sectorPathQuestion);
        if (!questionSector.is_open()){ cout << "Error"; return 0; }
        char buffer[20];

        while (!questionSector.eof()){ // выводим наш вопрос
            questionSector.read(buffer, sizeof(buffer));
            for (int i = 0; i < questionSector.gcount(); i++){
                cout << buffer[i];
            }
        }
        cout << "\n";
        questionSector.close();


        // ответ пользователя и сравнение с файлом ответа
        string answerUser, answerFile;
        cout << "Input answer question: ";
        cin.ignore(); // иначе в строку записывается сразу '\n'
        getline(cin, answerUser);

        ifstream answerSector;
        string sectorPathAnswer = "D:\\skillbox\\module19\\sectors\\answer";
        sectorPathAnswer += numSec;
        sectorPathAnswer += fileExtension;

        answerSector.open(sectorPathAnswer);
        if (!answerSector.is_open()){ cout << "Error"; return 0; }
        answerSector >> answerFile; // считываем ответ из файла

        answerFile == answerUser ? pointsPlayer++ : pointsSpectators++;
        cout << (answerFile == answerUser ? "Yes. True\n" : "No. No. No.\n");

        cout << "The correct answer: ";
        answerSector.seekg(0);
        while (!answerSector.eof()){ // выводим правильный ответ
            answerSector.read(buffer, sizeof(buffer));
            for (int i = 0; i < answerSector.gcount(); i++){
                cout << buffer[i];
            }
        }
        answerSector.close();

        cout << "\n";
        cout << "Points player: " << pointsPlayer << ". Points spectators: " << pointsSpectators << endl;
        cout << "\n\n";
    }

    

    cout << (pointsPlayer > pointsSpectators ? "Player WIN" : "Spectator WIN");
    

    // проблема такого методав том, что мы можем подобрать такое смещение, где
    // // будем считать 1 символ у 2-х значного числа. Например, число 11, курсор будет стоять сразу
    // // после первой однерки (1 курсор 1), тогда мы прочитам данное число как 1.
    // int offset;
    // cout << "Input offset sector: ";
    // cin >> offset;
    // sector.seekg(offset);
    // int num1;
    // sector >> num1;
    // cout << "Num: " << num1 << endl;
    // sector.seekg(0);

    return 0;
}