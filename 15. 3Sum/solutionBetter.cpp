#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> hashset;
    set<int> value;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int k = -1 * (nums[i] + nums[j]);
            if (value.find(k) != value.end())
            {
                vector<int> sample = {k, nums[i], nums[j]};
                sort(sample.begin(), sample.end());
                hashset.insert(sample);
            }
            value.insert(nums[j]);
        }
        value.clear();
    }

    vector<vector<int>> answer(hashset.begin(), hashset.end());
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // Input: nums = [-1,0,1,2,-1,-4]
    // Output: [[-1,-1,2],[-1,0,1]]

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> answer = threeSum(nums);
    for (auto it : answer)
    {
        for (int i = 0; i < it.size(); i++)
        {
            cout << it[i] << " ";
        }
        cout << endl;
    }

    return 0;
}