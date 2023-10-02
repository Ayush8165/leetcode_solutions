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

pair<bool, int> solve(TreeNode *root)
{
    if (root == NULL)
    {
        return {true, 0};
    }

    pair<bool, int> l = solve(root->left);
    pair<bool, int> r = solve(root->right);

    if (l.first == r.first and l.first == true)
    {
        if (l.second == r.second or abs(l.second - r.second) == 1)
        {
            return {true, max(l.second, r.second) + 1};
        }
    }
    return {false, 0};
}

bool isBalanced(TreeNode *root)
{
    pair<bool, int> ans = solve(root);
    return ans.first;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}