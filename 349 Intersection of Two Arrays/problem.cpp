#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    set<int> temp;
    int i = 0, j = 0;
    while (i < nums1.size() and j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
        else
        {
            temp.insert(nums1[i]);
            i++;
            j++;
        }
    }

    vector<int> ans;
    for (int i : temp)
    {
        ans.push_back(i);
    }

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> nums1, nums2;

    nums1 = {1, 2, 2, 1};
    nums2 = {2, 2};

    vector<int> ans;
    ans = intersection(nums1, nums2);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}