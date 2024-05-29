#include <iostream>

using namespace std;

class Drawable {
public:
    virtual void draw() const = 0;
};

class Circle : public Drawable {
public:
    void draw() const override {
        cout << "Drawing a circle." << endl;
    }
};

class Rectangle : public Drawable {
public:
    void draw() const override {
        cout << "Drawing a rectangle." << endl;
    }
};

int main() {
    Circle c;
    Rectangle r;

    c.draw();
    r.draw();

    return 0;
}
