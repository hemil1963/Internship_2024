#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
public:
    void sort(vector<int>& arr) {
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
    void heapify(vector<int>& arr, int n, int i) {
        int large = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[large]) {
            large = l;
        }

        if (r < n && arr[r] > arr[large]) {
            large = r;
        }

        if (large != i) {
            swap(arr[i], arr[large]);
            heapify(arr, n, large);
        }
    }
};

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    HeapSort h;
    h.sort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

