#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort activities by their finish time in ascending order
struct sort_pred
{
    // Overloaded operator() to compare pairs of integers
    bool operator()(const std::pair<int, int> &left, const std::pair<int, int> &right)
    {
        // Compare the second element (finish time) of the pairs
        if (left.second < right.second)
        {
            return true; // Return true if the left pair's finish time is less than the right's
        }
        return false; // Otherwise, return false
    }
};

// Function to print the maximum number of activities that can be selected
void printMaxActivities(vector<pair<int, int>> &arr)
{
    int i = 0; // Initialize the index of the first selected activity
    // Sort the activities based on their finish times
    sort(arr.begin(), arr.end(), sort_pred());

    // Print the index of the first selected activity
    cout << i << endl;

    // Iterate through the remaining activities
    for (int j = 1; j < arr.size(); j++)
    {
        // Check if the start time of the current activity is greater than or equal
        // to the finish time of the previously selected activity
        if (arr[j].first >= arr[i].second)
        {
            // Print the index of the selected activity
            cout << j << endl;

            // Update the index of the last selected activity
            i = j;
        }
    }
}

int main()
{
    // Create a vector to store pairs of integers representing activities
    // Each pair contains the start time (first) and finish time (second) of an activity
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(5, 9)); // Activity 1
    arr.push_back(make_pair(5, 7)); // Activity 2
    arr.push_back(make_pair(8, 9)); // Activity 3
    arr.push_back(make_pair(0, 6)); // Activity 4
    arr.push_back(make_pair(3, 4)); // Activity 5
    arr.push_back(make_pair(1, 2)); // Activity 6

    // Call the function to print the indices of the maximum number of activities
    printMaxActivities(arr);

    return 0;
}