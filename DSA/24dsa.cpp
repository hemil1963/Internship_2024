#include <iostream>
#include <queue>
#include <string>

using namespace std;

void binarynum(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; ++i) {
        string str = q.front();
        q.pop();

        cout << i << ": " << str << endl;

        q.push(str + "0");
        q.push(str + "1");
    }
}

int main() {
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << " are:\n";
    binarynum(n);

    return 0;
}

