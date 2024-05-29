#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Originator {
private:
    string state;

public:
    void setState(const string& newState) {
        state = newState;
    }

    string getState() const {
        return state;
    }

    Memento createMemento() const {
        return Memento(state);
    }


    void restoreFromMemento(const Memento& memento) {
        state = memento.getState();
    }
};


class Memento {
private:
    string state;

public:
    Memento(const string& s) : state(s) {}

    string getState() const {
        return state;
    }
};


class Caretaker {
private:
    vector<Memento> mementos;

public:
    void addMemento(const Memento& memento) {
        mementos.push_back(memento);
    }

    Memento getMemento(int index) const {
        if (index >= 0 && index < mementos.size()) {
            return mementos[index];
        }

        return Memento("");
    }
};

int main() {

    Originator o;
    Caretaker c;

    o.setState("s 1");
    c.addMemento(o.createMemento());

    o.setState("s 2");
    c.addMemento(o.createMemento());

    o.setState("s 3");

    cout << "Current State: " << o.getState() << endl;

    o.restoreFromMemento(c.getMemento(0));
    cout << "Restored State: " << o.getState() << endl;

    return 0;
}

