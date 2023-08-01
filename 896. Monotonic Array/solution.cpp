#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        vector<int> numsClone;
        numsClone = nums;

        sort(nums.begin(), nums.end());
        if (nums == numsClone)
        {
            return true;
        }
        else
        {
            reverse(nums.begin(), nums.end());
            if (nums == numsClone)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> nums = {1, 3, 2};
    Solution obj;
    bool flag = obj.isMonotonic(nums);
    if (flag)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}