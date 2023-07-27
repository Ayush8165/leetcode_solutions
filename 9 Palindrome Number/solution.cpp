#include <bits/stdc++.h>
using namespace std;

string toString(int x)
{
    string num;
    while (x > 0)
    {
        int temp = x % 10;
        x = x / 10;
        char ch = 48 + temp;
        num.push_back(ch);
    }
    return num;
}

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    string s;
    s = toString(x);

    int i = 0, j = s.length() - 1;
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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = -121;

    bool ans;
    ans = isPalindrome(n);
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}