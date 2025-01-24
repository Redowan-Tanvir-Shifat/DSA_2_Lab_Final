#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, const vector<int> &weights, const vector<int> &values, int n, vector<vector<int>> &mem) {
    if (n == 0 || W == 0) {
        return 0;
    }

    if (mem[n][W] != -1) {
        return mem[n][W];
    }

    if (weights[n - 1] > W) {
        mem[n][W] = knapsack(W, weights, values, n - 1, mem);
    }
    else {
        int withItem = values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1, mem);

        int withoutItem = knapsack(W, weights, values, n - 1, mem);

        mem[n][W] = max(withItem, withoutItem);
    }

    return mem[n][W];
}

int main() {
    int swords_weight = 15;
    int swords_value = 800;

    int meat_weight = 5;
    int meat_value = 200;

    int medicalKit_weight = 5;
    int medicalKit_value = 500;

    int logPose_weight = 10;
    int logPose_value = 300;

    int ingredients_weight = 5;
    int ingredients_value = 600;

    int tools_weight = 10;
    int tools_value = 700;

    int books_weight = 10;
    int books_value = 400;

    vector<int> weights = {swords_weight, meat_weight, medicalKit_weight, logPose_weight, ingredients_weight, tools_weight, books_weight};
    vector<int> values = {swords_value, meat_value, medicalKit_value, logPose_value, ingredients_value, tools_value, books_value};

    int capacity = 50;
    int n = values.size();

    vector<vector<int>> mem(n + 1, vector<int>(capacity + 1, -1));

    int maxValue = knapsack(capacity, weights, values, n, mem);

    cout << "The maximum value of the weights with bag capacity 50 is: " << maxValue << endl;

    return 0;
}
