#include <iostream>

using namespace std;

class Cmd {
public:
    virtual void exec() = 0;
};

class Light {
public:
    void on() {
        cout << "Light ON" << endl;
    }

    void off() {
        cout << "Light OFF" << endl;
    }
};

class OnCmd : public Cmd {
public:
    OnCmd(Light* l) : light(l) {}

    void exec() override {
        light->on();
    }

private:
    Light* light;
};

class OffCmd : public Cmd {
public:
    OffCmd(Light* l) : light(l) {}

    void exec() override {
        light->off();
    }

private:
    Light* light;
};

int main() {
    Light* l = new Light();
    Cmd* oc = new OnCmd(l);
    Cmd* of = new OffCmd(l);

    oc->exec();
    of->exec();

    return 0;
}

