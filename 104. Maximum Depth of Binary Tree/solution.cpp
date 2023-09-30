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

void solve(TreeNode *root, int cheight, int &height)
{
    if (root == NULL)
    {
        return;
    }

    if (cheight > height)
    {
        height = cheight;
    }

    solve(root->left, cheight + 1, height);
    solve(root->right, cheight + 1, height);
}

int maxDepth(TreeNode *root)
{
    int height = 0;
    int cheight = 0;
    solve(root, cheight, height);
    return height;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}