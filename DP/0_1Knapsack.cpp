#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem using recursion
int knapsack(int W, const vector<int> &weights, const vector<int> &values, int n)
{
    // Base case: no items left or capacity is 0
    if (n == 0 || W == 0)
    {
        return 0;
    }

    // If the weight of the nth item is more than the capacity, it cannot be included
    if (weights[n - 1] > W)
    {
        return knapsack(W, weights, values, n - 1);
    }

    // Case 1: Include the nth item
    int includeItem = values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1);

    // Case 2: Exclude the nth item
    int excludeItem = knapsack(W, weights, values, n - 1);

    // Return the maximum of including or excluding the nth item
    return max(includeItem, excludeItem);
}

int main()
{
    // Example input: values, weights, and knapsack capacity
    vector<int> values = {60, 100, 120}; // Values of the items
    vector<int> weights = {10, 20, 30};  // Weights of the items
    int W = 50;                          // Capacity of the knapsack

    int n = values.size(); // Number of items

    // Call the knapsack function
    int maxProfit = knapsack(W, weights, values, n);

    // Print the result
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
