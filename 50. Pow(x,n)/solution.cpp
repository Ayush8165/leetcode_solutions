#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n)
{
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    
    if (n == 0)
    {
        return 1;
    }

    double ans = x * pow(x, n - 1);

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    double x;
    cin >> x >> n;
    cout << myPow(x, n);
    return 0;
}