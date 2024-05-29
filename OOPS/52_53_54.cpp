#include <iostream>

class Color {
public:
    virtual void fill() const = 0;
};

class Red : public Color {
public:
    void fill() const override {
        std::cout << "Fill with red color." << std::endl;
    }
};

class Blue : public Color {
public:
    void fill() const override {
        std::cout << "Fill with blue color." << std::endl;
    }
};

class Shape {
protected:
    Color* color;

public:
    Shape(Color* c) : color(c) {}

    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    Circle(Color* c) : Shape(c) {}

    void draw() const override {
        std::cout << "Draw a circle. ";
        color->fill();
    }
};

class Square : public Shape {
public:
    Square(Color* c) : Shape(c) {}

    void draw() const override {
        std::cout << "Draw a square. ";
        color->fill();
    }
};

int main() {
    Color* r = new Red();
    Color* b = new Blue();

    Shape* rc = new Circle(r);
    Shape* bs = new Square(b);

    rc->draw();
    bs->draw();

    return 0;
}

