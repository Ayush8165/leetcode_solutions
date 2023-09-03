#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
    {
        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}

int fib(int n)
{
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    int ans = solve(n, dp);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << fib(n);

    return 0;
}