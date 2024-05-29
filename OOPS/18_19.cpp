#include <iostream>

using namespace std;

class MyComplex {
private:
    double real;
    double imag;

public:
    MyComplex() : real(0.0), imag(0.0) {}

    MyComplex(double r, double i) : real(r), imag(i) {}

    MyComplex operator+(const MyComplex& other) const {
        MyComplex ans;
        ans.real = real + other.real;
        ans.imag = imag + other.imag;
        return ans;
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    MyComplex n1(10, 12.3);
    MyComplex n2(11, 14.5);

    MyComplex sum = n1 + n2;

    cout << "Sum of complex numbers: ";
    sum.display();

    return 0;
}

