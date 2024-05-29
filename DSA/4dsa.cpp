#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findIntersection(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> intersection;

    for (int num : arr2) {
        if (set1.count(num)) {
            intersection.insert(num);
        }
    }

    return vector<int>(intersection.begin(), intersection.end());
}

int main() {

    vector<int> array1 = {5,6,7};
    vector<int> array2 = {7,8,9};


    vector<int> result = findIntersection(array1, array2);


    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
