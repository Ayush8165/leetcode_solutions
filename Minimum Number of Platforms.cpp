#include <bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n)
{
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);

    int platfor_needed = 1, result = 1;

    // Using two pointer here
    int i = 1, j = 0;
    while (i < n and j < n)
    {
        if (at[i] <= dt[j])
        {
            platfor_needed++;
            i++;
        }
        else if (at[i] > dt[j])
        {
            platfor_needed--;
            j++;
        }
        result = max(result, platfor_needed);
    }
    return result;
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