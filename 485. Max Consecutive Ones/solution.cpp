#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxi = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxi = max(maxi,count);
        }
        else
        {
            count = 0;
        }
    }

    return maxi;
}

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
    cout << findMaxConsecutiveOnes(temp);

    return 0;
}