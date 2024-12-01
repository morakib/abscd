#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <chrono>  // For timing

using namespace std;
using namespace chrono;

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Selection Sort
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

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; 
    }
    return arr;
}


void timeSort(void(*sortFunc)(vector<int>&), vector<int> arr, const string& sortName) {
    auto start = high_resolution_clock::now(); 
    sortFunc(arr);
    auto end = high_resolution_clock::now();   

    auto duration = duration_cast<milliseconds>(end - start);
    cout << sortName << " took " << duration.count() << " ms for " << arr.size() << " elements." << endl;
}

int main() {
    vector<int> sizes = {1000, 2000, 5000, 10000};

    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);

        // Time Bubble Sort
        vector<int> bubbleArr = arr;
        timeSort(bubbleSort, bubbleArr, "Bubble Sort");

        // Time Selection Sort
        vector<int> selectionArr = arr;
        timeSort(selectionSort, selectionArr, "Selection Sort");

        // Time Insertion Sort
        vector<int> insertionArr = arr;
        timeSort(insertionSort, insertionArr, "Insertion Sort");

        cout << endl;
    }

    return 0;
}