#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int ind = -1;

    // Find the breakpoint where a[i] < a[i+1]
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            // Break pt
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        // if no break pt, it means a[] is in decending order means next permutation is acending order, so reverse
        reverse(nums.begin(), nums.end());
    }
    else
    {
        // now swap the number just greater than nums[ind] (search from last as the rest array must be in acendiing order from last)
        for (int i = nums.size() - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        // now reverse the array from ind+1 to end, to make smallest possible from ind, hence you get nect permutation
        reverse(nums.begin() + ind + 1, nums.end());
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        array.push_back(temp);
    }

    nextPermutation(array);

    return 0;
}