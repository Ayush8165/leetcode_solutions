#include <bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> ans;

    // pushing in map
    map<int, int> mpp;
    for (auto it : nums)
    {
        mpp[it]++;
    }

    for (int i = 1; i <= nums.size(); i++)
    {
        if (mpp[i] > 0)
        {
            // present in map, i.e present in array
            continue;
        }
        else
        {
            // not present in array and map
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> nums;

    for (int i = 1; i < s.length(); i++)
    {
        int temp;
        temp = s[i] - '0';
        nums.push_back(temp);
        i++;
    }

    vector<int> answer = findDisappearedNumbers(nums);
    cout << "[";
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i];
        if (i + 1 < answer.size())
        {
            cout << ",";
        }
    }
    cout << "]";

    return 0;
}