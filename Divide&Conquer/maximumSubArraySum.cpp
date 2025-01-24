#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the maximum sum of a subarray crossing the midpoint
int maxCrossingSum(const vector<int> &arr, int low, int mid, int high) {
    int leftSum = INT_MIN; // Initialize left half max sum
    int sum = 0;

    // Find the maximum sum in the left half (from mid to low)
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    int rightSum = INT_MIN; // Initialize right half max sum
    sum = 0;

    // Find the maximum sum in the right half (from mid+1 to high)
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    // Return the sum of the maximum left and right halves crossing the midpoint
    return leftSum + rightSum;
}

// Function to find the maximum subarray sum using divide and conquer
int maxSubArraySum(const vector<int> &arr, int low, int high) {
    // Base case: If the array has only one element
    if (low == high) {
        return arr[low];
    }

    // Find the midpoint
    int mid = (low + high) / 2;

    // Recursively find the maximum subarray sum in the left half, right half, and crossing the midpoint
    int leftSum = maxSubArraySum(arr, low, mid);
    int rightSum = maxSubArraySum(arr, mid + 1, high);
    int crossSum = maxCrossingSum(arr, low, mid, high);

    // Return the maximum of the three
    return max(leftSum, max(rightSum, crossSum));
}

int main() {
    // Example array
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // Find the maximum subarray sum
    int maxSum = maxSubArraySum(arr, 0, arr.size() - 1);

    cout << "Maximum Subarray Sum: " << maxSum << endl;

    return 0;
}