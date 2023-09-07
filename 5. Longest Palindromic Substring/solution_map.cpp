#include <bits/stdc++.h>
using namespace std;

bool check(int index, int len, string s)
{
    int start = index - len;
    string ans = "";
    for (int i = start; i < index; i++)
    {
        ans = ans + s[i];
    }

    string s2 = ans;
    reverse(s2.begin(), s2.end());
    if (s2 == ans)
    {
        return true;
    }
    return false;
}

string make(int index, int len, string s)
{
    int start = index - len;
    string ans = "";
    for (int i = start; i < index; i++)
    {
        ans = ans + s[i];
    }

    return ans;
}

string longestPalindrome(string s)
{
    vector<pair<int, int> > data;
    pair<int, int> temp;

    int n = s.length();
    int arr[n + 1][n + 1];
    memset(arr, 0, sizeof(arr));

    string rev = s;
    reverse(rev.begin(), rev.end());

    int len = 0;
    int index = -1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (rev[i - 1] == s[j - 1])
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
                if (arr[i][j] > 0)
                {
                    temp.first = arr[i][j];
                    temp.second = j;
                    data.push_back(temp);
                }
            }
        }
    }

    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());

    for (auto it : data)
    {
        if (check(it.second, it.first, s))
        {
            return make(it.second, it.first, s);
        }
    }
    return "";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << longestPalindrome(s);

    return 0;
}