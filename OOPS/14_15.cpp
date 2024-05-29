#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() : name("Unknown"), age(0) {}

    Person(const string& pn) : name(pn), age(0) {}

    Person(const string& pn, int page) : name(pn), age(page) {}

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }
};

int main() {
    Person p1;
    Person p2("amber");
    Person p3("heard", 25);

    cout << "Name " << p1.getName() << ", Age  " << p1.getAge() << endl;
    cout << "Name  " << p2.getName() << ", Age  " << p2.getAge() << endl;
    cout << "Name  " << p3.getName() << ", Age  " << p3.getAge() << endl;

    return 0;
}

