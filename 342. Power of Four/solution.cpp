#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n)
{
    if (n == 1)
    {
        return true;
    }
    if (n < 1)
    {
        return false;
    }

    if (n % 4 == 0)
    {
        bool ans = isPowerOfFour(n / 4);
        return ans;
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << isPowerOfFour(n);

    return 0;
}