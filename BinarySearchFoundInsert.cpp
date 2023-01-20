#include <bits/stdc++.h>
using namespace std;

int binarySearch(int* arr, int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        else if (arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x);
        }
        else {
            return binarySearch(arr, mid + 1, high, x);
        }
    }
    return -1;
}

void insertElement(int* arr, int& size, int k, int x) {
    size++;
    for (int i = size - 1; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
}

void deleteElement(int* arr, int& size, int x) {
    int pos = binarySearch(arr, 0, size - 1, x);
    if (pos == -1) {
        cout << "Element not found in the array." << endl;
        return;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element to search for: ";
    cin >> x;

    int pos = binarySearch(arr, 0, size - 1, x);
    if (pos == -1) {
        int k;
        cout << "Enter the position to insert the element: ";
        cin >> k;
        insertElement(arr, size, k, x);
    }
    else {
        deleteElement(arr, size, x);
    }

    cout << "Modified array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
