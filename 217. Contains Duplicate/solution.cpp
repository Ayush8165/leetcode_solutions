#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    map<int, int> mpp;

    for (auto it : nums)
    {
        mpp[it]++;
    }

    for (auto it : mpp)
    {
        if (it.second > 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}