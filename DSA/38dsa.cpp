#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class G {
public:
    int V;
    vector<vector<int>> A;

    G(int V) {
        this->V = V;
        A.resize(V);
    }

    void E(int u, int v) {
        A[u].push_back(v);
    }

    bool C() {
        vector<int> I(V, 0);

        for (int i = 0; i < V; i++) {
            for (int n : A[i]) {
                I[n]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (I[i] == 0) {
                q.push(i);
            }
        }

        int visit = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visit++;

            for (int n : A[u]) {
                I[n]--;
                if (I[n] == 0) {
                    q.push(n);
                }
            }
        }

        return visit != V;
    }
};

int main() {
    G g(4);
    g.E(0, 1);
    g.E(1, 2);
    g.E(2, 0);
    g.E(2, 3);

    if (g.C()) {
        cout << "Cycle detected.";
    } else {
        cout << "No cycle detected.";
    }

    return 0;
}

