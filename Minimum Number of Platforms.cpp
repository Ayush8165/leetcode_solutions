#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    // sort()
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int at[n], dt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> at[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> dt[i];
    }

    cout << calculateMinPatforms(at, dt, n);

    return 0;
}