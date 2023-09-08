#include <bits/stdc++.h>
using namespace std;

int clipper(long long ans)
{
    long long a = pow(2, 31) * -1;
    long long b = (a * -1) - 1;
    if (ans >= a and ans <= b)
    {
        return int(ans);
    }
    else if (ans < a)
    {
        return int(a);
    }
    else
    {
        return int(b);
    }
}

int myAtoi(string s)
{
    vector<int> data;

    bool digit = false;
    bool positive = false;
    bool negative = false;
    bool sign = false;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            digit = true;
            data.push_back(s[i] - '0');
        }
        else if (s[i] == ' ' and digit == true)
        {
            if (digit or sign)
            {
                break;
            }
        }
        else if (isalpha(s[i]))
        {
            break;
        }
        else if (s[i] == '-')
        {
            if (digit or sign)
            {
                break;
            }
            negative = true;
            sign = true;
        }
        else if (s[i] == '+')
        {
            if (digit or sign)
            {
                break;
            }
            positive = true;
            sign = true;
        }
        else if (s[i] == '.')
        {
            break;
        }
    }

    if (positive and negative)
    {
        return 0;
    }
    else if (negative)
    {
        long long ans = 0;
        for (int i = 0; i < data.size(); i++)
        {
            ans = ans * 10 - data[i];
            ans = clipper(ans);
        }
        return int(ans);
    }
    else if (positive)
    {
        long long ans = 0;
        for (int i = 0; i < data.size(); i++)
        {
            ans = ans * 10 + data[i];
            ans = clipper(ans);
        }
        return int(ans);
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << myAtoi(s);

    return 0;
}