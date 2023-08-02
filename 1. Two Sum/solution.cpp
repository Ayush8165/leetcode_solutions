#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int sum;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                sum = nums[i] + nums[j];
                if (sum == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return vector(ans);
    }
};