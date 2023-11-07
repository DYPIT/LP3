#include <bits/stdc++.h>
using namespace std;
int dp[1002][1002];

// Function to solve the 0/1 Knapsack problem using dynamic programming
int solve(int W, vector<int> &wt, vector<int> &val, int n)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= W)
    {
        return max(val[n - 1] + solve(W - wt[n - 1], wt, val, n - 1), solve(W, wt, val, n - 1));
    }
    else if (wt[n - 1] > W)
    {
        return solve(W, wt, val, n - 1);
    }
}

int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    memset(dp, -1, sizeof(dp));

    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << solve(W, wt, val, n);

    return 0;
}