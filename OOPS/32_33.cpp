#include <iostream>
using namespace std;

class Coffee {
public:
    virtual int cost() const = 0;
};

class PlainCoffee : public Coffee {
public:
    int cost() const override {
        return 5;
    }
};
class Milk : public Coffee {
public:
    Milk(Coffee* coffee) : coffee(coffee) {}

    int cost() const override {
        return coffee->cost() + 2;
    }

private:
    Coffee* coffee;
};

class Sugar : public Coffee {
public:
    Sugar(Coffee* coffee) : coffee(coffee) {}

    int cost() const override {
        return coffee->cost() + 1;
    }

private:
    Coffee* coffee;
};

int main() {

    Coffee* c = new PlainCoffee();
    cout << "Cost of plain coffee: " << c->cost() << " dollars." << endl;


    c = new Milk(c);
   cout << "Cost of coffee with milk: " << c->cost() << " dollars." << endl;


    c = new Sugar(c);
   cout << "Cost of coffee with milk and sugar: " << c->cost() << " dollars." << endl;

    delete c;

    return 0;
}

