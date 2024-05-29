#include <iostream>
#include <string>

using namespace std;

class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void displayInfo() const = 0;
};

class ConcretePrototypeA : public Prototype {
private:
    string type;

public:
    ConcretePrototypeA(const string& t) : type(t) {}

    Prototype* clone() const override {
        return new ConcretePrototypeA(*this);
    }

    void displayInfo() const override {
        cout << "ConcretePrototypeA - Type: " << type << endl;
    }
};

class ConcretePrototypeB : public Prototype {
private:
    int value;

public:
    ConcretePrototypeB(int v) : value(v) {}

    Prototype* clone() const override {
        return new ConcretePrototypeB(*this);
    }

    void displayInfo() const override {
        cout << "ConcretePrototypeB - Value: " << value << endl;
    }
};

int main() {
    Prototype* a = new ConcretePrototypeA("TypeA");
    Prototype* c = a->clone();

    Prototype* b = new ConcretePrototypeB(42);
    Prototype* cb = b->clone();

    cout << "Original Object A:" << endl;
    a->displayInfo();

    cout << "\nCloned Object A:" << endl;
    c->displayInfo();

    cout << "\nOriginal Object B:" << endl;
    b->displayInfo();

    cout << "\nCloned Object B:" << endl;
    cb->displayInfo();

    return 0;
}

