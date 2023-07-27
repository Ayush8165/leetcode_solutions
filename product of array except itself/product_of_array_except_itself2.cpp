#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];

    // Input Array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // creating prfix array with shift of 1
    int prefix[n];
    prefix[0] = 1;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }

    // creating suffix array with shift of 1
    int suffix[n];
    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * arr[i + 1];
    }

    // product except itself
    for (int i = 0; i < n; i++)
    {
        arr[i] = prefix[i] * suffix[i];
    }

    print(arr, n);

    return 0;
}