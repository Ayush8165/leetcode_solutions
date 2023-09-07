#include <bits/stdc++.h>
using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    int len = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                len = max(len, dp[i][j]);
            }
        }
    }
    return len;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
        int input;
        cin >> input;
        temp.push_back(input);
    }
    vector<int> temp2;
    for (int j = 0; j < m; j++)
    {
        int input;
        cin >> input;
        temp2.push_back(input);
    }

    cout << findLength(temp, temp2);
    return 0;
}