#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class G {
private:
    unordered_map<int, list<int>> a;

public:
    void ae(int v, int w) {
        a[v].push_back(w);
        a[w].push_back(v);
    }

    void dfs(int v, vector<bool>& vis, vector<int>& comp) {
        vis[v] = true;
        comp.push_back(v);

        for (int n : a[v]) {
            if (!vis[n]) {
                dfs(n, vis, comp);
            }
        }
    }

    vector<vector<int>> connectcomp() {
        vector<bool> vis;
        vector<vector<int>> cc;

        for (const auto& p : a) {
            int v = p.first;
            if (!vis[v]) {
                vector<int> comp;
                dfs(v, vis, comp);
                cc.push_back(comp);
            }
        }

        return cc;
    }
};

int main() {
    G g;

    g.ae(0, 1);
    g.ae(1, 2);
    g.ae(2, 3);
    g.ae(4, 5);
    g.ae(6, 7);

    vector<vector<int>> cc = g.connectcomp();

    cout << "Connected Components:" << endl;
    for (const vector<int>& c : cc) {
        for (int v : c) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

