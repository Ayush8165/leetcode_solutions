// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// SOLVED BY KADANE ALGO

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        max_ending_here = max_ending_here + nums[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> nums;
    int temp;
    int count = 0;
    while (cin >> temp)
    {
        nums.push_back(temp);
        count++;
    }

    int answer;
    answer = maxSubArray(nums);
    cout << answer;

    return 0;
}