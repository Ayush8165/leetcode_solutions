#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> answer;
    vector<int> sample;

    if (nums.size() < 3)
        return answer;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    sample.push_back(nums[i]);
                    sample.push_back(nums[j]);
                    sample.push_back(nums[k]);

                    answer.push_back(sample);
                    sample.clear();
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    break;
                }
            }
        }
    }
    map<vector<int>, int> mpp;
    for (auto it : answer)
    {
        mpp[it]++;
    }
    answer.clear();
    for (auto it : mpp)
    {
        answer.push_back(it.first);
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