#include <bits/stdc++.h>
using namespace std;

int solve(string &s, string &rev, int i, int j, vector<vector<int>> &dp)
{
    if (i == s.length() or j == rev.length())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    // matched
    if (s[i] == rev[j])
    {
        ans = 1 + solve(s, rev, i + 1, j + 1, dp);
    }
    else
    {
        // not matched
        ans = max(solve(s, rev, i + 1, j, dp), solve(s, rev, i, j + 1, dp));
    }

    return dp[i][j] = ans;
}

int longestPalindromeSubseq(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    vector<vector<int>> dp(s.length(), vector<int>(rev.length(), -1));
    int ans = solve(s, rev, 0, 0, dp);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << longestPalindromeSubseq(s);

    return 0;
}