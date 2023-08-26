#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> candidates, int target, int index, int sum, vector<int> temp, set<vector<int>> &answer)
{
    if (index >= candidates.size() and sum != target)
    {
        return;
    }
    else if (sum > target)
    {
        return;
    }
    else if (sum == target)
    {
        sort(temp.begin(), temp.end());
        answer.insert(temp);
        return;
    }

    // not include
    solve(candidates, target, index + 1, sum, temp, answer);

    // include
    temp.push_back(candidates[index]);
    sum = sum + candidates[index];
    solve(candidates, target, index, sum, temp, answer);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    set<vector<int>> answer;
    vector<int> temp;
    int index = 0;
    int sum = 0;

    solve(candidates, target, index, sum, temp, answer);

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

    return 0;
}