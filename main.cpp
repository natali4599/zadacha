// #include "stdafx.h"
#include <iostream>
using namespace std;
const double PI = 3.1415926535897932384626433832795;


class shape{
    int abscissa, ordinate;
    public:
    shape();
    shape(int x, int y);
    virtual ~shape();

    void move(int x, int y);
    virtual void draw() = 0;
};
shape::shape() : abscissa(0), ordinate(0) {
}
shape::shape(int x, int y) : abscissa(x), ordinate(y) {
}
shape::~shape() {
}
void shape::move(int x, int y) {
    abscissa = x;
    ordinate = y;
}
class circle : public shape {
    float radius;

public:

circle(float rad);
circle(float rad, int newAbscissa, int newOrdinate);
~circle();
void setRadius(float newRadius);
float getRadius() const;
float getArea() const;
float getPerimeter() const;
int isEqual(circle c) const;
void setNewLocation(int newAbscissa, int newOrdinate);
void draw();
};
circle::circle(float rad) : shape(), radius(rad) {
    if(rad>10) {
        throw ("Radius over 10");
    }
}
circle::circle(float rad, int newAbscissa, int newOrdinate) : shape(newAbscissa, newOrdinate),
radius(rad) {
    if(newAbscissa>10||newAbscissa<-10) {
        throw ("newAbscissa over 10");
    }
    if(newOrdinate>10||newOrdinate<-10) {
        throw ("newAbscissa over 10");
    }
}
circle::~circle() {

}

void circle::setRadius(float newRadius) {
    radius = newRadius;
}
float circle::getRadius() const {
    return radius;
}

float circle::getArea() const {
    return PI*radius*radius;
}

float circle::getPerimeter() const {
    return 2*radius*PI;
}

int circle::isEqual(circle c) const {
    return (c.getArea()==getArea());
};

void circle::setNewLocation(int newAbscissa, int newOrdinate) {
    move(newAbscissa, newOrdinate);
    }

    void circle::draw() {
        cout << "Circle with radius: " << radius << endl << "Area:" << getArea() << endl <<
        "Perimeter:" << getPerimeter() << endl;
    }

    class rect : public shape {
        int width, height;
        public:
            rect(int w, int h);
            ~rect();

            void draw();
         };

rect::rect(int w, int h) : shape(), width(w), height(h) {
}

rect::~rect() {

}

void rect::draw() {
    cout << "Rectangle with width: " << width << " and height: " << height << endl;
}

int main(int argc, char* argv[]) {
    circle *c = new circle(10);
    shape *s;

    s = c;
    s->draw();

    circle *c2 = new circle(10,11,34);
    circle *c3 = new circle(11,5,5);
    return 0;
}