#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &nums, int index, vector<vector<int>> &answer)
{
    if (index >= nums.size() - 1)
    {
        answer.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        solve(nums, index + 1, answer);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> answer;
    int index = 0;

    solve(nums, index, answer);
    return answer;
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

    vector<vector<int>> answer = permute(temp);

    return 0;
}