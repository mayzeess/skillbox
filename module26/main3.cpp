#include <iostream>
#include <vector>
using namespace std;

class MonitorScreen{
    vector<vector<bool>> screen{50, vector<bool>(80, 0)}; // вектор типа данных bool, так как у нас все равно 0 или 1
    int x = 0, y = 0, height = 10, width = 10; // координаты начала окна и его размер. Изначально окно будет в координатаъ (0, 0) и размером 10 на 10
    void printScreen(vector<vector<bool>>& v){
        updateWindow(x, y, height, width, v);
        for (int i = 0; i < v.size(); i++){
            for(int j = 0; j < v[i].size(); j++){
                cout << v[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    void updateWindow(int x, int y, int height, int width, vector<vector<bool>>& v){
        for (int i = 0; i < v.size(); i++){
            for (int j = 0; j < v[i].size(); j++){
                v[i][j] = (i >= x && j >= y && i < x + height && j < y + width);
            }
        }
    }

    void moveScreen(int moveX, int moveY, int& x, int& y, int height, int width){
        x += moveX;
        y += moveY;
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x > 50 - height) x = 50 - height;
        if (y > 80 - width) y = 80 - width;

        cout << "New coordinate: " << x << ", " << y << ". Width: " << width << " Height: " << height << endl;
    }

    void resizeScreen(int newWidth, int newHeight){
        height = newHeight;
        width = newWidth;
        if (width > 80 - y) width = 80 - y;
        if (height > 50 - x) height = 50 - x;
        cout << "New size: " << "Width: " << width << " Height: " << height << endl;
    }

    public:
        void display(){
            printScreen(screen);
        }

        void move(int moveX, int moveY){
            moveScreen(moveX, moveY, x, y, height, width);
        }

        void resize(int newWidth, int newHeight){
            resizeScreen(newWidth, newHeight);
        }
};

void printCommand(){
    cout << "move - move the screen" << endl;
    cout << "resize - resize the window" << endl;
    cout << "display - show window" << endl;
    cout << "close - close window and exit program" << endl;
}

int main(){
    MonitorScreen* monitorScreen = new MonitorScreen;
    printCommand();
    string command;
    while(true){
        cout << "Input command: ";
        cin >> command;
        if (command == "move"){
            int x, y;
            cout << "Input specify the window offset (x, y): ";
            cin >> x >> y;
            monitorScreen->move(x, y);
        }
        else if (command == "resize"){
            cout << "Input new size window (x, y): ";
            int height, width;
            cin >> width >> height;
            monitorScreen->resize(width, height);
        }
        else if (command == "display"){
            monitorScreen->display();
        }
        else if (command == "close"){
            cout << "Exit program" << endl;
            delete monitorScreen;
            monitorScreen = nullptr;
            return 0;
        }
        else {
            cout << "Error command. Try again." << endl;
            printCommand();
        }
    }
    
    return 0;
}