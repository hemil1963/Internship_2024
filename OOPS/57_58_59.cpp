#include <iostream>

using namespace std;

class Target {
public:
    virtual void request() const = 0;
};

class Adaptee {
public:
    void specificRequest() const {
        cout << "Adaptee's specific request." << endl;
    }
};

class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* a) : adaptee(a) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

int main() {
    Adaptee* a = new Adaptee();
    Target* t = new Adapter(a);

    t->request();
    return 0;
}

