#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());
        vector<int> freq(max - min + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i] - min]++;
        }
        nums.clear();

        int k = 0;
        for (int i = 0; i < max - min + 1; i++)
        {
            if (freq[i] > 0)
            {
                nums.push_back(i + min);
                k++;
            }
        }
        return k;
        for (int i = 0; i < nums.size(); i++)
        {
            return nums[i];
        }
    }
};