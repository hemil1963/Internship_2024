#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void countSort(vector<int>& A) {
    int n = A.size();

    int maxVal = *max_element(A.begin(), A.end());
    vector<int> C(maxVal + 1, 0);

    for (int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        C[i] += C[i - 1];
    }

    vector<int> B(n);

    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

int main() {
    vector<int> arr = {4, 2, 10, 5, 3, 1};

    countSort(arr);

    cout << "Sorted array: ";
    for (int i : arr) {
        cout << i << " ";
    }

    return 0;
}

