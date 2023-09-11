#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string target, string str)
{
    if (target == "")
    {
        return true;
    }

    int j = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (target[j] == str[i])
        {
            j++;
            if (j >= target.length())
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string target, str;
    cin >> target >> str;

    cout << isSubsequence(target, str);

    return 0;
}