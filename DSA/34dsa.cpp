#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class G {
private:
    unordered_map<int, list<int>> a;

public:
    void av(int v) {
        if (a.find(v) == a.end()) {
            a[v] = list<int>();

        } else {
            cout << "V " << v << " exists." << endl;
        }
    }

    void ae(int s, int d) {
        if (a.find(s) != a.end() && a.find(d) != a.end()) {
            a[s].push_back(d);
            a[d].push_back(s);

        } else {
            cout << "Invalid" << endl;
        }
    }

    void rv(int v) {
        if (a.find(v) != a.end()) {
            a.erase(v);

            for (auto& p : a) {
                p.second.remove(v);
            }

        } else {
            cout << "V " << v << " not found" << endl;
        }
    }

    void re(int s, int d) {
        if (a.find(s) != a.end() && a.find(d) != a.end()) {
            a[s].remove(d);
            a[d].remove(s);

        } else {
            cout << "Invalid " << endl;
        }
    }

    void dg() {
        cout << "Graph :" << endl;
        for (const auto& p : a) {
            cout << p.first << " -> ";
            for (const int& n : p.second) {
                cout << n << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    G g;

    g.av(1);
    g.av(2);
    g.av(3);
    g.av(4);

    g.ae(1, 2);
    g.ae(2, 3);
    g.ae(3, 4);
    g.ae(4, 1);

    g.dg();

    g.rv(3);
    g.re(1, 2);

    g.dg();

    return 0;
}

