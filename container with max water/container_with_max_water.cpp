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

int solve(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    int max_area = INT_MIN;
    int area;
    while (i < j)
    {
        area = (j - i) * min(arr[i], arr[j]);
        if (area > max_area)
        {
            max_area = area;
        }
        if (arr[i] < arr[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return max_area;
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

    cout << solve(arr, n);

    return 0;
}