#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &nums1)
{
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl
         << endl;
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1, p2 = n - 1, i = m + n - 1;

    while (p2 >= 0)
    {
        if (p1 >= 0 && nums1[p1] > nums2[p2])
        {
            nums1[i--] = nums1[p1--];
        }
        else
        {
            nums1[i--] = nums2[p2--];
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;

    vector<int> nums1;
    for (int i = 0; i < m + n; i++)
    {
        int temp;
        cin >> temp;
        nums1.push_back(temp);
    }

    // print(nums1);

    vector<int> nums2;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums2.push_back(temp);
    }
    // print(nums2);

    merge(nums1, m, nums2, n);

    return 0;
}