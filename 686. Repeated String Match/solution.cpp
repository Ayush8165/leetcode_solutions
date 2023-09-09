// GIVES TLE

#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b)
{
    int n = a.find(b);
    if (n >= 0 and n <= a.length())
    {
        return true;
    }
    return false;
}

int repeatedStringMatch(string a, string b)
{
    int m = a.length();
    int n = b.length();

    int minl;
    if (n % m != 0)
    {
        minl = (n / m) + 1;
    }
    else
    {
        minl = n / m;
    }

    string temp = a;
    for (int i = 0; i < minl - 1; i++)
    {
        a = a + temp;
    }

    while (1)
    {
        if (check(a, b))
        {
            return minl;
        }
        a = a + temp;
        minl++;
        if (minl >= m * 2)
        {
            break;
        }
    }
    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    cout << repeatedStringMatch(a, b);

    return 0;
}