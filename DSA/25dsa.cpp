#include <bits/stdc++.h>
using namespace std;
class Datastack {
public:
    stack<int> st,mn;

    void push(int x)
    {
        if(st.empty() || x<=mn.top())
            mn.push(x);
        st.push(x);
    }

    void pop()
    {
        if(st.top()==mn.top())
            mn.pop();
        st.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return mn.top();
    }
};
int main()
{
    Datastack* ds = new Datastack();
    ds->push(3);
    ds->push(2);
    ds->push(1);
    int l1 = ds->getMin();
    ds->pop();
    int l2 = ds->top();
    int l3 = ds->getMin();

    cout<<l1<<endl;
    cout<<l2<<endl;
    cout<<l3<<endl;

    return 0;
}
