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

    int k;
    cin >> k;
    k = k % n;
    reverse(arr + 0, arr + n);
    print(arr, n);
    reverse(arr + 0, arr + k);
    print(arr, n);
    reverse(arr + k, arr + n);

    print(arr, n);

    return 0;
}