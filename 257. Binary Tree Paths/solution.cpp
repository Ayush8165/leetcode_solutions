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

void solve(TreeNode *root, vector<string> &ans, string temp)
{
    string s = to_string(root->val);
    temp = temp + s;
    temp = temp + "->";
    if (root->left == NULL and root->right != NULL)
    {
        solve(root->right, ans, temp);
    }
    else if (root->left != NULL and root->right == NULL)
    {
        solve(root->left, ans, temp);
    }
    else if (root->left == NULL and root->right == NULL)
    {
        temp.pop_back();
        temp.pop_back();
        ans.push_back(temp);
        return;
    }
    else
    {
        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
    }
}

vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    if (root == NULL)
    {
        return ans;
    }
    string temp = "";
    solve(root, ans, temp);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}