#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n)
{
    if (n == 1)
    {
        return true;
    }
    if (n < 1)
    {
        return false;
    }

    if (n % 3 == 0)
    {
        bool ans = isPowerOfThree(n / 3);
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

    cout << isPowerOfThree(n);

    return 0;
}