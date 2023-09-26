#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2)
{
    // Write your code here.
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, -1));
    int ans = 0;

    for (int i = 1; i <= str1.length(); i++)
    {
        for (int j = 1; j <= str2.length(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans + 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}