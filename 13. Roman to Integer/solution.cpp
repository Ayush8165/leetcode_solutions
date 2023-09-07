#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;

    int ans = roman[s[0]];
    for (int i = 1; i < s.length(); i++)
    {
        if (roman[s[i]] > roman[s[i - 1]])
        {
            // special
            ans = ans - roman[s[i - 1]] + roman[s[i]] - roman[s[i - 1]];
            continue;
        }
        ans = ans + roman[s[i]];
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << romanToInt(s);

    return 0;
}