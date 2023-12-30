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

    bool found = false;
    int left = 0, right = s.length() - 1;
    int i = 0, j = 0;
    int minLength = s.length();
    int count = mppt.size();
    bool flag1 = false, flag2 = false;

    while (i < s.length())
    {
        flag1 = false;
        flag2 = false;
        // do till count is not = 0
        while (count != 0 and j < s.length())
        {
            flag1 = true;
            if (mppt.find(s[j]) != mppt.end())
            {
                mppt[s[j]]--;
                if (mppt[s[j]] == 0)
                {
                    count--;
                }
            }
            j++;
        }
        // do till count == 0
        while (count == 0)
        {
            flag2 = true;
            if (mppt.find(s[i]) != mppt.end())
            {
                mppt[s[i]]++;
                if (mppt[s[i]] > 0)
                {
                    count++;
                    if (j - i <= minLength)
                    {
                        // cout << "found" << endl;
                        found = true;
                        left = i + 1;
                        right = j;
                        minLength = j - i;
                    }
                }
            }
            i++;
        }
        if (flag1 == false or flag2 == false)
        {
            break;
        }
    }
    if (found == true)
    {
        return s.substr(left - 1, minLength);
    }
    return "";
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