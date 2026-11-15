#include <iostream>
#include <cmath>
#include <numbers> // для числа pi
using namespace std;

struct BoundingBoxDimensions
{
    double height;
    double width;
};

class Shape{
public:
    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual string type() = 0;
    void printParams(Shape *shape){
        cout << "Type: " << shape->type() << endl;
        cout << "\tSquare: " << shape->square() << endl;
        cout << "\tWidth: " << shape->dimensions().width << endl;
        cout << "\tHeight: " << shape->dimensions().height << endl;
    }
};

class Circle : virtual public Shape {
    double r; // радиус круга
    double pi = numbers::pi;

    double square(){
        return pi * pow(r, 2);
    }

    BoundingBoxDimensions dimensions(){
        return {r * 2, r * 2};
    }

    string type(){
        return "Circle";
    }

public:
    Circle(double inR): r(inR){
        if (inR <= 0) { // если радиус будет отрицательный или равен 0, то ставим по умолчанию 1
            r = 1;
        }
    }

};

class Rectangle : virtual public Shape {
    double x, y;
    double square(){
        return x * y;
    }

    BoundingBoxDimensions dimensions(){
        return {x, y};
    }

    string type(){
        return "Rectangle";
    }

public:
    Rectangle(double inX, double inY) : x(inX), y(inY){
        if (inX <= 0){
            x = 1;
        }
        if (inY <= 0){
            y = 1;
        }
    }
};

class Triangle : virtual public Shape{
    double a, b, c; // три стороны треугольника
    double p;

    double square(){
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    BoundingBoxDimensions dimensions(){
        double r = a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c)));
        return {2 * r, 2 * r};
    }

    string type(){ 
        return "Triangle"; 
    }

public:
    Triangle(double inA, double inB, double inC) : a(inA), b(inB), c(inC){
        p = (a + b + c) / 2; // полупериметр
        if (inA <= 0){
            a = 1;
        }
        if (inB <= 0){
            b = 1;
        }
        if (inC <= 0){
            c = 1;
        }
    }

};

int main(){
    Triangle t(3, 4, 5);
    t.printParams(&t);

    Circle c(4.2);
    c.printParams(&c);

    Rectangle r(3.5, 8.2);
    r.printParams(&r);
    return 0;
}