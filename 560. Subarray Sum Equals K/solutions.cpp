#include <bits/stdc++.h>
using namespace std;

void print(vector<int> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << matrix[i] << " ";
    }
    cout << endl;
}

int subarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    map<int, int> mp;
    int res = 0, ans = 0;
    long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            res++;
        }
        ans = sum - k;

        res += mp[ans];
        mp[sum]++;
    }
    return res;
}

// int subarraySum(vector<int> &nums, int k)
// {
//     int left = 0;
//     int right = 0;
//     int count = 0;
//     int sum = nums[0];

//     while (left <= right)
//     {
//         while (left <= right and sum > k)
//         {
//             sum = sum - nums[left];
//             left++;
//         }
//         if (sum == k)
//         {
//             count++;
//         }
//         right++;
//         if (right < nums.size())
//         {
//             sum = sum + nums[right];
//         }
//         else
//         {
//             right--;
//             left++;
//             if (left == right)
//             {
//                 sum = nums[left];
//             }
//             else
//             {
//                 sum = sum - nums[left];
//             }
//         }
//     }

//     return count;
// }

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
        int input;
        cin >> input;
        temp.push_back(input);
    }

    int k;
    cin >> k;

    cout << subarraySum(temp, k);
    return 0;
}