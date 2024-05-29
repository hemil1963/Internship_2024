#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int>& A, int exp) {
    const int n = A.size();
    const int base = 10;

    vector<int> B(n);
    vector<int> C(base, 0);

    for (int i = 0; i < n; i++) {
        C[(A[i] / exp) % base]++;
    }

    for (int i = 1; i < base; i++) {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        B[C[(A[i] / exp) % base] - 1] = A[i];
        C[(A[i] / exp) % base]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

void radixSort(vector<int>& A) {
    int maxVal = *max_element(A.begin(), A.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(A, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}

