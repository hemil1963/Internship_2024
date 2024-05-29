#include <iostream>

using namespace std;

class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual void createProductA() = 0;
    virtual void createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    void createProductA() {
        cout << "ConcreteFactory1: Creating ProductA1" << endl;
    }

    void createProductB() {
        cout << "ConcreteFactory1: Creating ProductB1" << endl;
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    void createProductA() {
        cout << "ConcreteFactory2: Creating ProductA2" << endl;
    }

    void createProductB() {
        cout << "ConcreteFactory2: Creating ProductB2" << endl;
    }
};

class ProductA {
public:
    virtual ~ProductA() {}
    virtual void display() = 0;
};

class ConcreteProductA1 : public ProductA {
public:
    void display() {
        cout << "ConcreteProductA1" << endl;
    }
};

class ConcreteProductA2 : public ProductA {
public:
    void display() {
        cout << "ConcreteProductA2" << endl;
    }
};

class ProductB {
public:
    virtual ~ProductB() {}
    virtual void show() = 0;
};

class ConcreteProductB1 : public ProductB {
public:
    void show() {
        cout << "ConcreteProductB1" << endl;
    }
};

class ConcreteProductB2 : public ProductB {
public:
    void show() {
        cout << "ConcreteProductB2" << endl;
    }
};

int main() {
    ConcreteFactory1 factory1;
    factory1.createProductA();
    factory1.createProductB();

    ConcreteFactory2 factory2;
    factory2.createProductA();
    factory2.createProductB();

    return 0;
}
