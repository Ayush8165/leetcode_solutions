#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    if (s == t)
        return t;

    if (s.length() == 0 or t.length() == 0)
        return "";

    if (t.length() > s.length())
        return "";

    // map characters of string t
    map<char, int> mppt;
    for (int i = 0; i < t.length(); i++)
    {
        mppt[t[i]]++;
    }

    int count = t.length();
    int start = 0, end = 0;
    string ans = s;

    while (count != 0 and end != s.length())
    {
        while (count > 0 and end < s.length())
        {
            if (mppt.find(s[end]) != mppt.end())
            {
                mppt[s[end]]--;
                if (mppt[s[end]] == 0)
                    count--;
            }
            end++;
        }
        while (count == 0)
        {
            if (mppt.find(s[start]) != mppt.end())
            {
                count++;
                mppt[s[start]]++;
                string temp = s.substr(start, end - start);
                if (ans.length() > temp.length())
                {
                    ans = temp;
                }
            }
            start++;
        }
    }

    if (count != 0 and end == s.length())
    {
        // find last char in string present in the map
        // for (int i = 0; i < s.length(); i++)
        // {
        //     if (mppt.find(s[i]) != mppt.end())
        //     {
        //         end = i;
        //     }
        // }

        while (count != t.length())
        {
            if (mppt.find(s[start]) != mppt.end())
            {
                count++;
                mppt[s[start]]++;
                string temp = s.substr(start, end - start + 1);
                if (ans.length() > temp.length())
                {
                    ans = temp;
                }
            }
            start++;
        }
    }

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s, t;
    cin >> s >> t;

    cout << minWindow(s, t);

    return 0;
}