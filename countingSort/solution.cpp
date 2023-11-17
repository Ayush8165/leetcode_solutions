#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &nums)
{
    // find the maximum and minimum element
    int max = INT_MIN;
    int min = INT_MAX;
    for (auto it : nums)
    {
        if (max < it)
        {
            max = it;
        }
        if (min > it)
        {
            min = it;
        }
    }

    // create frequency array/vector
    vector<int> freq(max + 1 - min);
    int shift = abs(min);
    for (auto it : nums)
    {
        freq[it + shift]++;
    }

    // convert frequenct array to a prefix sum array
    int sum = 0;
    for (int i = 0; i < freq.size(); i++)
    {
        sum = sum + freq[i];
        freq[i] = sum;
    }

    // iterate the nums vector backward
    // whatever be the value we get, go to that index in freq array
    // whatever be the value at that index in freq array -> value-1
    // now in a new array, at index (value-1) store the index no of freq array
    vector<int> store(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int value = nums[i];
        freq[value + shift]--;
        store[freq[value + shift]] = value;
    }
    nums = store;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> nums{
        10,
        67,
        35,
        378,
        4,
        -100,
        0,
        11,
        1,
        0,
        3,
        -1,
    };

    countSort(nums);

    for (auto it : nums)
    {
        cout << it << " ";
    }

    return 0;
}