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

vector<int> getTopView(TreeNode *root)
{
    queue<pair<TreeNode *, int>> val;

    // line value
    map<int, int> mpp;

    val.push({root, 0});

    while (val.empty() == false)
    {
        TreeNode *temp = val.front().first;
        int tln = val.front().second;

        if (mpp[tln] == 0)
        {
            mpp[tln] = temp->val;
        }

        if (temp->left != NULL)
        {
            val.push({temp->left, tln - 1});
        }

        if (temp->right != NULL)
        {
            val.push({temp->right, tln + 1});
        }

        val.pop();
    }

    vector<int> ans;
    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}