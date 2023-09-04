#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 1)
    {
        return true;
    }
    if (n < 1)
    {
        return false;
    }

    bool ans;

    if (n % 2 == 0)
    {
        ans = isPowerOfTwo(n / 2);
    }
    else
    {
        ans = false;
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << isPowerOfTwo(n);

    return 0;
}