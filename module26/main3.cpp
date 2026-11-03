#include <iostream>
#include <vector>
using namespace std;

class Window{
    int x, y, height, width; // координаты начала окна и его размер

    void positionWindow(int x, int y, int height, int width, vector<vector<bool>>& v){ // функция которая задает позицию окна, располагает его в нужном месте
        for (int i = 0; i < v.size(); i++){
            for (int j = 0; j < v[i].size(); j++){
                v[i][j] = (i >= x && j >= y && i < x + height && j < y + width);
            }
        }
    }

    void moveWindow(int moveX, int moveY, int& x, int& y, int height, int width, int px, int py){
        x += moveX;
        y += moveY;
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x > px - height) x = px - height;
        if (y > py - width) y = py - width;

        cout << "New coordinate: " << x << ", " << y << ". Width: " << width << " Height: " << height << endl;
    }

    void resizeWindow(int newWidth, int newHeight, int px, int py){
        height = newHeight;
        width = newWidth;
        if (width > py - y) width = py - y;
        if (height > px - x) height = px - x;
        if (width < 0) width = 1;
        if (height < 0) height = 1;
        cout << "New size: " << "Width: " << width << " Height: " << height << endl;
    }

    public:
        Window(int startX, int startY, int startH, int startW){
            x = startX;
            y = startY;
            height = startH;
            width = startW;
        }

        void move(int moveX, int moveY, int px, int py){
            moveWindow(moveX, moveY, x, y, height, width, px, py);
        }

        void updatePositionWindow(vector<vector<bool>>& v){
            positionWindow(x, y, height, width, v);
        }

        void resize(int newWidth, int newHeight, int px, int py){
            resizeWindow(newWidth, newHeight, px, py);
        }
};

class MonitorScreen{
    int px, py; // размер экрана монитора
    vector<vector<bool>> screen; // вектор типа данных bool, так как у нас все равно 0 или 1
    Window* window = new Window(0, 0, 10, 10);

    void printScreen(){
        window->updatePositionWindow(screen);
        for (int i = 0; i < screen.size(); i++){
            for(int j = 0; j < screen[i].size(); j++){
                cout << screen[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }

    public:
        MonitorScreen(int x, int y){
            px = x;
            py = y;
            screen.resize(px, vector<bool>(py, 0));
        }

        void display(){
            printScreen();
        }

        void move(int moveX, int moveY){
            window->move(moveX, moveY, px, py);
        }

        void resize(int newWidth, int newHeight){
            window->resize(newWidth, newHeight, px, py);
        }

        void deleteWindow(){
            delete window;
            window = nullptr;
        }
};

void printCommand(){
    cout << "move - move the screen" << endl;
    cout << "resize - resize the window" << endl;
    cout << "display - show window" << endl;
    cout << "close - close window and exit program" << endl;
}

int main(){
    MonitorScreen* monitorScreen = new MonitorScreen(50, 80);
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
            monitorScreen->deleteWindow();
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