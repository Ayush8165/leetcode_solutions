#include <bits/stdc++.h>
using namespace std;

void solve(map<string, int> &str1, string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            ans = ans + s[j];
            str1[ans]++;
        }
        ans = "";
    }
}

bool check_palindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (s == rev)
    {
        return true;
    }
    return false;
}

string longestPalindrome(string s)
{
    // generate all substrings
    map<string, int> str1;
    solve(str1, s);

    // now match longest substring in both maps
    string answer;
    int len = 0;
    for (auto it : str1)
    {
        if (check_palindrome(it.first))
        {
            if (it.first.length() > len)
            {
                len = it.first.length();
                answer = it.first;
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