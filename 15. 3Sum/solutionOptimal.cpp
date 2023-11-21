#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> answer;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i != 0 and nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                answer.push_back({nums[i], nums[j], nums[k]});
                j++;
                while (nums[j] == nums[j - 1] and j < k)
                    j++;
                k--;
                while (nums[k] == nums[k + 1] and k > j)
                    k--;
            }
        }
    }
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