#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            temp = nums[i];
            break;
        }
    }
    return temp;
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
    cout << findDuplicate(nums);

    return 0;
}