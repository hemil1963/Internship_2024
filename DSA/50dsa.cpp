#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findOcc(const vector<int>& A, int target) {
    int first = -1, last = -1;
    int n = A.size();

    int l = 0, h = n - 1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (A[m] == target) {
            first = m;
            h = m - 1;
        } else if (A[m] < target) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    l = 0;
    h = n - 1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (A[m] == target) {
            last = m;
            l = m + 1;
        } else if (A[m] < target) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    return make_pair(first, last);
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 4, 5, 6, 7};
    int target = 3;

    pair<int, int> o = findOcc(arr, target);

    cout << "First occurrence: " << o.first << endl;
    cout << "Last occurrence: " << o.second << endl;

    return 0;
}

