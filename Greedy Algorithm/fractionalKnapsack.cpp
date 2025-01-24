/*
Task 1: Fractional Knapsack
Given the weights and profits of N items, in the form of {profit, weight} put
these items in a knapsack of capacity W to get the maximum total profit in
the knapsack. In Fractional Knapsack, we can break items for maximizing the
total value of the knapsack.
Input: arr[] = {{60, 10}, {100, 20}, {120, 30}}, W = 50
Output: 240
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30
kg. Hence total price will be 60+100+(2/3)(120) = 240
Input: arr[] = {{500, 30}}, W = 10
Output: 166.667
*/

#include <bits/stdc++.h>
using namespace std;

// Custom comparator to sort items based on their profit-to-weight ratio
struct sort_pred
{
    bool operator()(const pair<int, int> &left, const pair<int, int> &right)
    {
        // Calculate the profit-to-weight ratio for the two items
        double r1 = (double)left.first / left.second;
        double r2 = (double)right.first / right.second;

        // Sort items in descending order of their profit-to-weight ratio
        return r1 > r2;
    }
};

// Function to calculate the maximum profit that can be achieved
// with a given weight limit using the fractional knapsack approach
void printMaxProfit(vector<pair<int, int>> &arr, int w)
{
    int profit = 0; // Variable to store the total profit

    // Step 1: Sort the items based on their profit-to-weight ratio in descending order
    sort(arr.begin(), arr.end(), sort_pred());

    // Step 2: Iterate through the sorted items
    for (int k = 0; k < arr.size(); k++)
    {
        // If the current item's weight is less than or equal to the remaining weight capacity
        if (w <= arr[k].second)
        {
            // Take a fraction of the item to completely fill the knapsack
            double fraction = (double)w / arr[k].second; // Fraction of the item that can be taken
            profit += arr[k].first * fraction;           // Add the proportional profit
            w = 0;                                       // Knapsack is now full
            break;                                       // Exit the loop
        }
        else
        {
            // Take the entire item
            w -= arr[k].second;     // Reduce the remaining weight capacity
            profit += arr[k].first; // Add the full profit of the item
        }
    }

    // Step 3: Print the maximum profit
    cout << profit << endl;
}

int main()
{
    // List of items where each pair represents (profit, weight)
    vector<pair<int, int>> arr;
    arr.push_back(make_pair(60, 10));  // Item with profit 60 and weight 10
    arr.push_back(make_pair(100, 20)); // Item with profit 100 and weight 20
    arr.push_back(make_pair(120, 30)); // Item with profit 120 and weight 30

    int w = 50; // Maximum weight capacity of the knapsack

    // Function call to calculate the maximum profit
    printMaxProfit(arr, w);

    return 0;
}
