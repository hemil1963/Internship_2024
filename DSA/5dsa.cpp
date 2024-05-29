#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 0) {
        return;
    }
    k = k % n;

    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    int k;
    cout << "Enter the number of positions to rotate: ";
    cin >> k;

    rotateArray(array, k);
    cout << "Rotated Array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

