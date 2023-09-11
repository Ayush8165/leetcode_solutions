#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.length();
    int m = needle.length();

    for (int i = 0; i < n - m + 1; i++)
    {
        string temp = haystack.substr(i, m);
        if (temp == needle)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string haystack, needle;
    cin >> haystack >> needle;

    cout << strStr(haystack, needle);
    return 0;
}