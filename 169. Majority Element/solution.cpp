#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > (nums.size() / 2))
        {
            return it.first;
        }
    }
    return -1;
}

// int majorityElement(vector<int> &nums)
// {
//     // Creating frequency array
//     int max = INT_MIN;
//     int min = INT_MAX;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] >= max)
//         {
//             max = nums[i];
//         }
//         if (nums[i] <= min)
//         {
//             min = nums[i];
//         }
//     }

//     if (min < 0)
//     {
//         int n = abs(min) + max + 1;
//         int freq[abs(min) + max + 1];
//         fill(freq, freq + n, 0);
//         for (int i = 0; i < n; i++)
//         {
//             freq[nums[i] + abs(min)]++;
//         }

//         int high = -1;
//         int index = -1;
//         for (int i = 0; i < max + 1; i++)
//         {
//             if (freq[i] >= high)
//             {
//                 high = freq[i];
//                 index = i;
//             }
//         }
//         return index - abs(min);
//     }
//     else
//     {
//         int freq[max + 1];
//         fill(freq, freq + max + 1, 0);
//         for (int i = 0; i < nums.size(); i++)
//         {
//             freq[nums[i]]++;
//         }

//         int high = -1;
//         int index = -1;
//         for (int i = 0; i < max + 1; i++)
//         {
//             if (freq[i] >= high)
//             {
//                 high = freq[i];
//                 index = i;
//             }
//         }
//         return index;
//     }
// }

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    cout << majorityElement(nums);

    return 0;
}