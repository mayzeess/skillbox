#include <iostream>
#include <cmath>
using namespace std;

enum color{ orange, blue, green, yellow, None }; // None - нет цвета

string printColorFigure(int color); // для вывода цвета фигуры

class Figure{
public:
    string name = ""; // добавил название фигуры в общий класс
    double centerCoordinateX = 0, centerCoordinateY = 0;
    color figureColor = color::None; // по умалчанию цвета нет
    double boundingRectangleHeight = 0, boundingRectangleWidth = 0; // еще дополнительно 
    // добавил высоту и ширину описывающего прямоугольника, так как он тоже есть у каждой фигуры
    double square = 0; // в каждой фигуре есть площадь

    void inputCenterCoordinate(double centerCoordinateX, double centerCoordinateY){ // общая функция для записи координат центра фигуры
        this->centerCoordinateX = centerCoordinateX;
        this->centerCoordinateY = centerCoordinateY;
    }

    void printInfo(){ // вывод инфорамации о фигуре, также в общем классе
        cout << "Figure: " << name << ". Color: " << printColorFigure(figureColor) << endl;
        cout << "Cener coordinate: " << centerCoordinateX << " " << centerCoordinateY << endl;
        cout << "Square: " << square << endl;
        cout << "Bounding rectangle:\nWidth: " << boundingRectangleWidth << endl;
        cout << "Height: " << boundingRectangleHeight << endl;
    }

    Figure(string inName, color inColor) : name(inName), figureColor(inColor){} // чтобы при создании фигур можно было сразу добавлять цвета
};

class Circle : public Figure{
    double radius = 0;

    void squareCircle(){
        square = atan(1) * 4 * radius * radius;
    }

    void boundingRectangle(){
        boundingRectangleHeight = radius * 2 + 1;
        boundingRectangleWidth = boundingRectangleHeight;
    }

    public:
    void inputRadius(double radius){ // можно без this, а принимать просто аргумент inRadius
        // и сделать прсотоее присваивание inRadius = radius, но я решил использовать this
        this->radius = radius;
        boundingRectangle(); // после ввода радиуса сразу считам опис. прямоугольник и площадь
        squareCircle();
    }

    Circle(string inName = "Circle", color inColor = color::None) : Figure(inName, inColor){} // по умолчанию цвет None

};

class Triangle : public Figure{
    double edgeLength = 0;

    void squareTriangle(){
        square = edgeLength * edgeLength * sqrt(3) / 4;
    }

    void boundingRectangle(){ // ТУТ ПОСЧИТАТЬ ОПИС ПРЯМОУГ

    }

public:
    void inputEdgeLength(double edgeLength){
        this->edgeLength = edgeLength;
        squareTriangle();
    }

    Triangle(string inName = "Triangle", color inColor = color::None) : Figure(inName, inColor){}
};


class Square : public Figure{
    double side = 0;

    void squareSquare(){
        square = side * side;
    }

    void boundingRectangle(){
        boundingRectangleHeight = side + 1;
        boundingRectangleWidth = boundingRectangleHeight;
    }

public:
    void inputSquare(double side){
        this->side = side;
        squareSquare();
        boundingRectangle();
    }

    Square(string inName = "Square", color inColor = color::None) : Figure(inName, inColor){}
};

class Rectangle : public Figure{
    double height = 0, width = 0;

    void squareRectangle(){
        square = height * width;
    }

    void boundingRectangle(){
        boundingRectangleHeight = height + 1;
        boundingRectangleWidth = width + 1;
    }

public:
    void inputHeighAndWeight(double height, double width){
        this->height = height;
        this->width = width;
        squareRectangle();
        boundingRectangle();
    }

    Rectangle(string inName = "Rectangle", color inColor = color::yellow) : Figure(inName, inColor) {};
};


string printColorFigure(int color){
    if (color == color::orange){
        return "orange";
    }
    else if (color == color::blue){
        return "blue";
    }
    else if (color == color::green){
        return "green";
    }
    else if (color == color::yellow){
        return "yellow";
    }
    else{
        return "none";
    }
}

void printCommand(){
    cout << "List command: " << endl;
    cout << "- circle\n- square\n- triangle\n- rectangle\n- exit" << endl;
}

int main(){
    string command;
    double x, y;
    printCommand();
    while (true){
        cout << "Input command: ";
        cin >> command;
        if (command == "circle"){
            Circle* circle = new Circle("Circle", color::orange);
            double radius;
            cout << "Input center coordinate (x, y): ";
            cin >> x >> y;
            circle->inputCenterCoordinate(x, y);
            cout << "Input radius: ";
            cin >> radius;
            circle->inputRadius(radius);
            circle->printInfo();
            delete circle;
            circle = nullptr;
        }
        else if (command == "triangle"){
            Triangle* triangle = new Triangle("Triangle", color::blue);
            cout << "Input center coordinate (x, y): ";
            cin >> x >> y;
            triangle->inputCenterCoordinate(x, y);
            double endgeLenght;
            cout << "Input edge length: ";
            cin >> endgeLenght;
            triangle->inputEdgeLength(endgeLenght);
            triangle->printInfo();
            delete triangle;
            triangle = nullptr;
        }
        else if (command == "square"){
            Square* square = new Square("Square", color::green);
            cout << "Input center coordinate (x, y): ";
            cin >> x >> y;
            square->inputCenterCoordinate(x, y);
            cout << "Input side square: ";
            double side;
            cin >> side;
            square->inputSquare(side);
            square->printInfo();
            delete square;
            square = nullptr;
        }
        else if (command == "rectangle"){
            Rectangle* rectangle = new Rectangle;
            cout << "Input center coordinate (x, y): ";
            cin >> x >> y;
            rectangle->inputCenterCoordinate(x, y);
            cout << "Input heigh and width: ";
            double height, width;
            cin >> height >> width;
            rectangle->inputHeighAndWeight(height, width);
            rectangle->printInfo();
            delete rectangle;
            rectangle = nullptr;
        }
        else if (command == "exit"){
            cout << "Exit program" << endl;
            return 0;
        }
        else {
            cout << "Error command. Try again" << endl;
            printCommand();
        }
    }
    return 0;
}