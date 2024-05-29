#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    queue<int> q1;
    queue<int> q2;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    int k = 3;
    int s = q1.size();

    stack<int> st;
    int j = k % s;

    for (int i = 0; i < j; i++) {
        int t = q1.front();

        q1.pop();
        st.push(t);
    }
    while (!st.empty()) {
       int t = st.top();

        st.pop();
        q2.push(t);
    }

    while (!q1.empty()) {
        int t=q1.front();
        q1.pop();
        q2.push(t);
    }
    while (!q2.empty()) {
        cout << q2.front() << " ";
        q2.pop();
    }

    return 0;
}

