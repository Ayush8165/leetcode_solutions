#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    int pref[n];
    pref[0] = 1;
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        product = product * arr[i];
        pref[i + 1] = product;
    }

    int suf[n];
    suf[n - 1] = 1;
    product = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        product = product * arr[i];
        suf[i - 1] = product;
    }

    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = pref[i] * (suf[i]);
        cout << ans[i] << " ";
    }

    return 0;
}