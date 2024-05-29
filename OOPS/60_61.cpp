#include <iostream>
#include <string>

using namespace std;

class Mediator {
public:
    virtual void sendMessage(const string& message, class Colleague* colleague) const = 0;
};

class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* m) : mediator(m) {}

    virtual void receiveMessage(const string& message) const = 0;
    virtual void sendMessage(const string& message) const {
        mediator->sendMessage(message, this);
    }
};

class ConcreteMediator : public Mediator {
public:
    void sendMessage(const string& message, Colleague* colleague) const override {
        colleague->receiveMessage(message);
    }
};

class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA(Mediator* m) : Colleague(m) {}

    void receiveMessage(const string& message) const override {
        cout << "ConcreteColleagueA received message: " << message << endl;
    }
};

class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB(Mediator* m) : Colleague(m) {}

    void receiveMessage(const string& message) const override {
        cout << "ConcreteColleagueB received message: " << message << endl;
    }
};

int main() {
    ConcreteMediator m;

    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);

    colleagueA.sendMessage("Hello from Colleague A!");
    colleagueB.sendMessage("Hi from Colleague B!");

    return 0;
}

