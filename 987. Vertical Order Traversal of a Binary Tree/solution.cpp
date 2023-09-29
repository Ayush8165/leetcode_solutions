#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};

bool mycondition(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
{
    if (a.second.second < b.second.second)
    {
        return true;
    }
    else if (a.second.second > b.second.second)
    {
        return false;
    }
    else
    {
        if (a.first < b.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    // root, curr, level
    queue<pair<TreeNode *, pair<int, int>>> que;
    int min = 0, max = 0, curr = 0, level = 0;
    que.push({root, {curr, level}});

    // root->val, curr, level
    vector<pair<int, pair<int, int>>> sample;

    while (que.empty() == false)
    {
        TreeNode *troot = que.front().first;
        curr = que.front().second.first;
        level = que.front().second.second;

        if (curr > max)
        {
            max = curr;
        }
        if (curr < min)
        {
            min = curr;
        }

        if (troot->left != NULL)
        {
            que.push({troot->left, {curr - 1, level + 1}});
        }
        if (troot->right != NULL)
        {
            que.push({troot->right, {curr + 1, level + 1}});
        }

        sample.push_back({troot->val, {curr, level}});
        que.pop();
    }

    int size = max - min + 1;
    int factor = min * -1;
    // vector<vector<int>> solution(size);
    vector<vector<int>> solution;
    vector<pair<int, pair<int, int>>> unsort;

    vector<int> ans;

    for (int i = min; i < max + 1; i++)
    {
        for (auto it : sample)
        {
            if (it.second.first == i)
            {
                unsort.push_back(it);
            }
        }
        // sort this unsort vector with respect to level
        sort(unsort.begin(), unsort.end(), mycondition);

        for (auto it2 : unsort)
        {
            ans.push_back(it2.first);
        }
        solution.push_back(ans);
        ans.clear();
        unsort.clear();
    }

    return solution;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}