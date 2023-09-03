#include <bits/stdc++.h>
using namespace std;

int solve(int n, int i, vector<int> &dp)
{
    // base case
    if (i == n)
    {
        return 1;
    }
    if (i > n)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    return dp[i] = (solve(n, i + 1, dp) + solve(n, i + 2, dp));
}

int climbStairs(int n)
{
    int index = 0;
    vector<int> dp(n + 1, -1);
    int count = solve(n, index, dp);
    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << climbStairs(n);

    return 0;
}