#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<int> temp, set<vector<int>> &answer)
{
    // base case
    if (index >= nums.size())
    {
        sort(temp.begin(), temp.end());
        answer.insert(temp);
        return;
    }

    // not include
    solve(nums, index + 1, temp, answer);

    // include
    temp.push_back(nums[index]);
    solve(nums, index + 1, temp, answer);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    set<vector<int>> answer;
    vector<int> temp;
    int index = 0;

    solve(nums, index, temp, answer);

    // convert set to vector
    vector<vector<int>> final;
    for (auto it = answer.begin(); it != answer.end(); it++)
    {
        final.push_back(*it);
    }
    return final;
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

    vector<vector<int>> answer = subsetsWithDup(temp);

    return 0;
}