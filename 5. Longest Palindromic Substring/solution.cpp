#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string longestPalindrome(string s)
{
    int n = s.length();
    if (n <= 1)
    {
        return s;
    }

    string longest = "";
    string answer;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            string sub = s.substr(j, i);
            if (check(sub))
            {
                if (sub.length() > longest.length())
                {
                    answer = sub;
                }
            }
        }
    }
    return answer;
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