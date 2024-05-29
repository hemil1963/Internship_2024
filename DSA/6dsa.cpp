#include <iostream>

#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(vector<int>& sortedArray) {
    sortedArray.erase(unique(sortedArray.begin(), sortedArray.end()), sortedArray.end());
}

int main() {

    vector<int> sortedArray = {12,15,17,17,19,19};


    removeDuplicates(sortedArray);


    cout << "Array without duplicates: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

