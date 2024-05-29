#include <iostream>
#include <stack>
using namespace std;

void toh(int n, char l, char m,
                  char r)
{
    if (n == 0) {
        return;
    }
    toh(n - 1, l, r, m);
    cout << "disk " << n << " from " << l<< " to " << m << endl;
    toh(n - 1, r, m, l);
}

int main()
{
    int N = 3;
    toh(N, 'L','M','R');
    return 0;
}
