#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int i;
    for (i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
    return i;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << missingNumber(nums);

    return 0;
}