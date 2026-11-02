#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

class Track{
    public:
        string name;
        tm date;
        int seconds;
};

class AudioPlayer{
    time_t t = time(nullptr);
    tm locale = *localtime(&t);
    vector<Track> music{ // просто вручную создан список записей. Список музыки
        Track{"music 1", locale, 100},
        Track{"music 2", locale, 210},
        Track{"music 3", locale, 180},
        Track{"music 4", locale, 130},
        Track{"music 5", locale, 100},
        Track{"music 6", locale, 210},
        Track{"music 7", locale, 221},
        Track{"music 8", locale, 116},
        Track{"music 9", locale, 199},
        Track{"music 10", locale, 139}
    };

    void printMusic(Track music){ // печать информации о музыки
        int minutes = music.seconds / 60;
        cout << music.name << "\n" << asctime(&music.date) << minutes << ":" << (music.seconds - minutes * 60) << endl;
        cout << "MUSIC PLAY" << endl;
    }

    bool playMusic = false, pauseMusic = false;

    public:
        void play(){
            string name;
            cout << "Input name music: ";
            cin.ignore();
            getline(cin, name);
            for(int i = 0; i < music.size(); i++){
                if (name == music[i].name){
                    printMusic(music[i]);
                    playMusic = true;
                    pauseMusic = false;
                    return;
                }
            }
            cout << "Error name music" << endl;
        }

        void pause(){
            if (!pauseMusic && playMusic){
                cout << "Music pause" << endl;
                pauseMusic = true;
            }
        }

        void next(){
            printMusic(music[rand() % 10]);
            playMusic = true;
            pauseMusic = false;
        }

        void stop(){
            if (playMusic){
                cout << "Stop music" << endl;
            }
            playMusic = false;
        }

};

void printListCommand(){
    cout << "play - play music by name" << endl;
    cout << "pause - pause music" << endl;
    cout << "next - play random music next" << endl;
    cout << "stop - stop music" << endl;
    cout << "exit - exit program" << endl;
}

int main(){
    AudioPlayer* audio = new AudioPlayer;
    printListCommand();
    string command;
    
    while(true){
        cout << "Input command: ";
        cin >> command;
        if (command == "play"){
            audio->play();
        }
        else if (command == "pause"){
            audio->pause();
        }
        else if (command == "next"){
            audio->next();
        }
        else if (command == "stop"){
            audio->stop(); 
        }
        else if (command == "exit"){
            cout << "Exit program" << endl;
            delete audio;
            audio = nullptr;
            return 0;
        }
        else {
            cout << "Error command" << endl;
        }
    }
    return 0;
}