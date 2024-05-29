#include <iostream>
#include <string>

using namespace std;

class Approver {
protected:
    Approver* successor;

public:
    Approver() : successor(nullptr) {}

    void setSuccessor(Approver* nextApprover) {
        successor = nextApprover;
    }

    virtual void processRequest(int amount) = 0;
};

class Manager : public Approver {
public:
    void processRequest(int amount) override {
        if (amount <= 1000) {
            cout << "Manager approves the purchase request of $" << amount << endl;
        } else if (successor != nullptr) {
            cout << "Manager cannot approve. Passing to the next approver." << endl;
            successor->processRequest(amount);
        } else {
            cout << "No more approvers. Request denied." << endl;
        }
    }
};

class Director : public Approver {
public:
    void processRequest(int amount) override {
        if (amount <= 5000) {
            cout << "Director approves the purchase request of $" << amount << endl;
        } else if (successor != nullptr) {
            cout << "Director cannot approve. Passing to the next approver." << endl;
            successor->processRequest(amount);
        } else {
            cout << "No more approvers. Request denied." << endl;
        }
    }
};

class VicePresident : public Approver {
public:
    void processRequest(int amount) override {
        if (amount <= 10000) {
            cout << "Vice President approves the purchase request of $" << amount << endl;
        } else if (successor != nullptr) {
            cout << "Vice President cannot approve. Passing to the next approver." << endl;
            successor->processRequest(amount);
        } else {
            cout << "No more approvers. Request denied." << endl;
        }
    }
};

int main() {
    Approver* manager = new Manager();
    Approver* director = new Director();
    Approver* vicePresident = new VicePresident();

    manager->setSuccessor(director);
    director->setSuccessor(vicePresident);

    manager->processRequest(800);
    manager->processRequest(3500);
    manager->processRequest(12000);
    manager->processRequest(25000);

    delete manager;
    delete director;
    delete vicePresident;

    return 0;
}

