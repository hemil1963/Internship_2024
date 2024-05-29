#include <iostream>
#include <stack>

using namespace std;

string rev(string& str) {
    stack<char> st;

    for (char c : inputStr) {
        st.push(c);
    }

    string revst = "";

    while (!st.empty()) {
        revst += st.top();
        st.pop();
    }

    return revst;
}

int main() {
    string str = "Hello, World!";
    string ans = rev(str);

    cout << ans << endl;

    return 0;
}
