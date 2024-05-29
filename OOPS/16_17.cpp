#include <iostream>

using namespace std;

class Calculator {
public:
    int add(int x, int y) {
        return x + y;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    Calculator c;

    int result1 = c.add(7, 3);
    cout << "Result (two integers): " << result1 << endl;

    int result2 = c.add(1, 2, 3);
    cout << "Result (three integers): " << result2 << endl;

    return 0;
}

