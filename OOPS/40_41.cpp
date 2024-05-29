#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Iterator {
public:
    virtual string getNext() = 0;
    virtual bool hasNext() = 0;
};

class PersonList {
private:
    vector<string> people;

public:
    void addPerson(const string& person) {
        people.push_back(person);
    }

    Iterator* createIterator() {
        return new PersonIterator(this);
    }

    string getPersonAt(int index) {
        return people[index];
    }

    int getSize() {
        return people.size();
    }
};

class PersonIterator : public Iterator {
private:
    PersonList* personList;
    int currentIndex;

public:
    PersonIterator(PersonList* list) : personList(list), currentIndex(0) {}

    string getNext() override {
        if (hasNext()) {
            return personList->getPersonAt(currentIndex++);
        }
        return "";
    }

    bool hasNext() override {
        return currentIndex < personList->getSize();
    }
};

int main() {
    PersonList p;
    p.addPerson("ved");
    p.addPerson("yash");


    Iterator* i = p.createIterator();

    cout << "People: ";
    while (i->hasNext()) {
        cout << i->getNext() << " ";
    }
    cout << endl;
    return 0;
}

