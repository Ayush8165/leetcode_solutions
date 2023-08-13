#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int i;
        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] == target)
            {
                break;
            }
            if(nums[i] > target)
            {
                break;
            }
        }
        return i;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    return 0;
}