#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    string type;

public:
    Engine(const string& engineType) : type(engineType) {}

    void start() {
        cout << "Engine started." << endl;
    }
};

class Car {
private:
    string model;
    Engine ce;

public:
    Car(const string& carModel, const string& engineType) : model(carModel), ce(engineType) {}

    void drive() {
        cout << "Car " << model << " is moving." << endl;
        ce.start();
    }
};

int main() {

    Car myCar("audi", "a6");
    myCar.drive();

    return 0;
}

