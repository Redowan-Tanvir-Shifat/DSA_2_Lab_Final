// Divide and Conquer Algorithm

#include <iostream>
#include <vector>

using namespace std;

// Function to partition the vector into two parts
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Pointer for smaller element

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;                  // Move the pointer for smaller element
            swap(arr[i], arr[j]); // Swap the elements
        }
    }
    // Place the pivot in the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the pivot index
}

// QuickSort function
void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        // Partition the vector and get the pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Helper function to print the vector
void printVector(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example vector
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original Array: ";
    printVector(arr);

    // Sort the vector using QuickSort
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    printVector(arr);

    return 0;
}