// FULLY ACCEPTED

#include <bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string a, string b)
{
    int m = a.length();
    int n = b.length();

    int repeat = n / m;
    int len = 1;

    string temp = a;

    for (int i = 0; i < repeat + 2; i++)
    {
        // to find string b in string a std::string::npos is when string b is not present in the string a
        if (a.find(b) != std::string::npos)
        {
            return len;
        }
        a = a + temp;
        len++;
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