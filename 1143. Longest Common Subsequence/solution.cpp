#include <bits/stdc++.h>
using namespace std;

int solve(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    // base cases
    if (i == text1.length())
    {
        return 0;
    }
    if (j == text2.length())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    // Match
    if (text1[i] == text2[j])
    {
        ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
    }
    // Not Match
    else
    {
        ans = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
    }

    return dp[i][j] = ans;
}

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    int ans = solve(text1, text2, 0, 0, dp);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text1, text2;
    cin >> text1 >> text2;

    cout << longestCommonSubsequence(text1, text2);

    return 0;
}