#include <iostream>
#include <cmath>

using namespace std;

class MathOperations {
public:
    static double func(double num) {
        return sqrt(num);
    }
};

int main() {

    double number = 49;
    double ans = MathOperations::func(number);

    cout << "Square root of " << number << ": " << ans << endl;

    return 0;
}

