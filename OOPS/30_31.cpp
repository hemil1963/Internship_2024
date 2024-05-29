#include <iostream>
#include <vector>

using namespace std;

class Sub {
public:
    void addObs(O* obs);
    void remObs(O* obs);
    void notifyObs(int data);

private:
    vector<O*> obsList;
};

class O {
public:
    virtual void upd(int data) = 0;
};

class CO : public O {
public:
    void upd(int data) override {
        cout << "Received update: " << data <<endl;
    }
};

void Sub::addObs(O* obs) {
    obsList.push_back(obs);
}

void Sub::remObs(O* obs) {
    auto it = find(obsList.begin(), obsList.end(), obs);
    if (it != obsList.end()) {
        obsList.erase(it);
    }
}

void Sub::notifyObs(int data) {
    for (O* o : obsList) {
        o->upd(data);
    }
}

int main() {
    Sub s;

    CO o1;
    CO o2;

    s.addObs(&o1);
    s.addObs(&o2);

    s.notifyObs(42);

    return 0;
}

