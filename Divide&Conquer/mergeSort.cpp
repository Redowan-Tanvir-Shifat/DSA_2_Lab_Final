
// Divide and Conquer Algorithm

#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r, int arrIndex[]) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int a_index[n1];
    int b[n2];
    int b_index[n2];

    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
        a_index[i] = arrIndex[l + i];
    }

    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
        b_index[i] = arrIndex[mid + 1 + i];
    }

    // now merge process
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            arrIndex[k] = a_index[i];
            k++;
            i++;
        }
        else {
            arr[k] = b[j];
            arrIndex[k] = b_index[j];
            k++;
            j++;
        }
    }

    while (i < n1) {
        arr[k] = a[i];
        arrIndex[k] = a_index[i];
        k++;
        i++;
    }

    while (j < n2) {
        arr[k] = b[j];
        arrIndex[k] = b_index[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r, int arrIndex[]) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, arrIndex);
        mergeSort(arr, mid + 1, r, arrIndex);
        merge(arr, l, mid, r, arrIndex);
    }
}

int main() {
    int n = 8;
    int arr[] = {9, 4, 7, 3, 2, 9, 5, 1};
    int arrIndx[n];

    cout << " Before sort-> ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        arrIndx[i] = i;
    }
    cout << endl;

    mergeSort(arr, 0, n - 1, arrIndx);

    cout << " After sort-> ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << " After sort (Index) -> ";
    for (int i = 0; i < n; i++) {
        cout << arrIndx[i] << " ";
    }
    cout << endl;

    return 0;
}