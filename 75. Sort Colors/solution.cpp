#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    // Using 3 pointers we will create 3 different sections of areas for 0 1 and 2
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
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

    sortColors(array);

    return 0;
}