#include <bits/stdc++.h>
using namespace std;

long long beautifulSubarrays(vector<int> &nums)
{
    // xor till now
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    long long count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        xr = xr ^ nums[i];

        // for xor to be 0
        int x = xr ^ 0;
        count = count + mpp[x];
        mpp[xr]++;
    }
    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << beautifulSubarrays(arr);

    return 0;
}