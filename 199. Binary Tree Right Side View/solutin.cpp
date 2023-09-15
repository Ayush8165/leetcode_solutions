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

TreeNode *buildTree()
{
    int x;
    if (cin >> x)
    {
        // Null value
        if (x == -1)
        {
            return NULL;
        }
        else
        {
            TreeNode *root = new TreeNode(x);
            root->left = buildTree();
            root->right = buildTree();

            return root;
        }
    }
    else
    {
        return NULL;
    }
}

void solve(TreeNode *root, vector<int> &ans, int &lev, int curr)
{
    if (root == NULL)
    {
        return;
    }

    // check level
    if (curr > lev)
    {
        lev = curr;
        // cout << root->val << " ";
        ans.push_back(root->val);
    }

    // send to right side
    solve(root->right, ans, lev, curr + 1);
    solve(root->left, ans, lev, curr + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    int lev = -1;
    solve(root, ans, lev, 0);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    TreeNode *tree = buildTree();
    vector<int> ans = rightSideView(tree);

    return 0;
}