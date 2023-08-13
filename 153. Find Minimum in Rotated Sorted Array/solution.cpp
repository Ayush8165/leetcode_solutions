#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        int answer = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] <= nums[nums.size() - 1])
            {
                answer = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return nums[answer];
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}