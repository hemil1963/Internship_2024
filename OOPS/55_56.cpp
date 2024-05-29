#include <iostream>
#include <vector>

using namespace std;

class Graphic {
public:
    virtual void show() const = 0;
};

class Leaf : public Graphic {
private:
    string name;

public:
    Leaf(const string& n) : name(n) {}

    void show() const override {
        cout << "Leaf: " << name << endl;
    }
};

class Composite : public Graphic {
private:
    vector<Graphic*> elements;

public:
    void add(Graphic* element) {
        elements.push_back(element);
    }

    void show() const override {
        cout << "Composite:" << endl;
        for (const auto& element : elements) {
            element->show();
        }
    }
};

int main() {
    Leaf* l1 = new Leaf("l 1");
    Leaf* l2 = new Leaf("l 2");
    Leaf* l3 = new Leaf("l 3");

    Composite* composite1 = new Composite();
    composite1->add(l1);
    composite1->add(l2);

    Composite* composite2 = new Composite();
    composite2->add(l3);

    Composite* root = new Composite();
    root->add(composite1);
    root->add(composite2);

    root->show();
    return 0;
}

