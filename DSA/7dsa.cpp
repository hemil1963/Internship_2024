#include <iostream>

#include <bits/stdc++.h>

using namespace std;

vector<int> func(const vector<int>& arrA, const vector<int>& arrB) {
    int sizeA = arrA.size();
    int sizeB = arrB.size();

    vector<int> mergedArray;
    mergedArray.reserve(sizeA + sizeB);

    int i = 0, j = 0;

    while (i < sizeA && j < sizeB) {
        if (arrA[i] <= arrB[j]) {
            mergedArray.push_back(arrA[i]);
            ++i;
        } else {
            mergedArray.push_back(arrB[j]);
            ++j;
        }
    }

    while (i < sizeA) {
        mergedArray.push_back(arrA[i]);
        ++i;
    }

    while (j < sizeB) {
        mergedArray.push_back(arrB[j]);
        ++j;
    }

    return mergedArray;
}

int main() {
    vector<int> arrayA = {10, 20, 30, 40};
    vector<int> arrayB = {15, 25, 35, 45};

    vector<int> mergedArray = func(arrayA, arrayB);

    cout << "Merged Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

