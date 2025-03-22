#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        vector<int> temp;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }
        while (j <= right) {
            temp.push_back(arr[j++]);
        }
        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }
    }
}

int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void displayArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;
    int n, element, choice, target, result;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        arr.push_back(element);
    }

    while (true) {
        cout << "\nChoose an option: \n";
        cout << "1. Test Selection Sort\n";
        cout << "2. Test Merge Sort\n";
        cout << "3. Test Linear Search\n";
        cout << "4. Test Binary Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Original array: ";
                displayArray(arr);
                selectionSort(arr);
                cout << "Array after Selection Sort: ";
                displayArray(arr);
                break;

            case 2:
                cout << "Original array: ";
                displayArray(arr);
                mergeSort(arr, 0, arr.size() - 1);
                cout << "Array after Merge Sort: ";
                displayArray(arr);
                break;

            case 3:
                cout << "Enter element to search for: ";
                cin >> target;
                result = linearSearch(arr, target);
                if (result != -1) {
                    cout << "Element found at index " << result << endl;
                } else {
                    cout << "Element not found!" << endl;
                }
                break;

            case 4:
                cout << "Enter element to search for: ";
                cin >> target;
                bubbleSort(arr);
                cout << "Array sorted for Binary Search: ";
                displayArray(arr);
                result = binarySearch(arr, target);
                if (result != -1) {
                    cout << "Element found at index " << result << endl;
                } else {
                    cout << "Element not found!" << endl;
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

