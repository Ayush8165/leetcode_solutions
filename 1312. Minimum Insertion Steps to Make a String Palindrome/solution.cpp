#include <bits/stdc++.h>
using namespace std;

int solve(string &text1, string &text2, int i, int j, vector<vector<int> > &dp)
{
    // base condition
    if (i == text1.length() or j == text2.length())
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;
    // match
    if (text1[i] == text2[j])
    {
        ans = 1 + solve(text1, text2, i + 1, j + 1, dp);
    }
    else
    {
        // mot match
        ans = max(solve(text1, text2, i + 1, j, dp), solve(text1, text2, i, j + 1, dp));
    }

    return dp[i][j] = ans;
}

int longestPalindromeSubsequence(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    vector<vector<int> > dp(s.length(), vector<int>(rev.length(), -1));
    return solve(s, rev, 0, 0, dp);
}

// length of string - longest palindromic subsequence
int minInsertions(string s)
{
    return s.length() - longestPalindromeSubsequence(s);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << minInsertions(s);

    return 0;
}