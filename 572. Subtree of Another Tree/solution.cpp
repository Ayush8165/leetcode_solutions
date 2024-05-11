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

void solve(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        ans.push_back(-1);
        return;
    }
    ans.push_back(root->val);
    solve(root->left, ans);
    solve(root->right, ans);
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    vector<int> left;
    solve(p, left);
    vector<int> right;
    solve(q, right);

    if (left == right)
    {
        return true;
    }
    return false;
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}