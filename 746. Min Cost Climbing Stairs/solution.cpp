#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> cost, int n, vector<int> &dp)
{
    // base case
    if (n == 0)
    {
        return cost[0];
    }
    if (n == 1)
    {
        return cost[1];
    }

    // STEP 3
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // STEP 2
    dp[n] = cost[n] + min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return dp[n];
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();

    // STEP 1
    vector<int> dp(n + 1, -1);

    int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
        int input;
        cin >> input;
        temp.push_back(input);
    }
    cout << minCostClimbingStairs(temp);
    return 0;
}