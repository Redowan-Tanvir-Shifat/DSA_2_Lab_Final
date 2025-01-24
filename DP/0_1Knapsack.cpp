#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int> &weights, const vector<int> &values, int n, vector<vector<int>> &mem)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (mem[n][W] != -1)
    {
        return mem[n][W];
    }

    if (weights[n - 1] > W)
    {
        mem[n][W] = knapsack(W, weights, values, n - 1, mem);
    }
    else
    {
        int withItem = values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1, mem);

        int withoutItem = knapsack(W, weights, values, n - 1, mem);

        mem[n][W] = max(withItem, withoutItem);
    }

    return mem[n][W];
}

int main()
{
    // Example input: values, weights, and knapsack capacity
    vector<int> values = {60, 100, 120}; // Values of the items
    vector<int> weights = {10, 20, 30};  // Weights of the items
    int W = 50;                          // Capacity of the knapsack

    int n = values.size(); // Number of items

    vector<vector<int>> mem(n + 1, vector<int>(W + 1, -1));

    // Call the knapsack function
    int maxProfit = knapsack(W, weights, values, n, mem);

    // Print the result
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
