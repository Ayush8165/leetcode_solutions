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
    while (cin >> x)
    {
        if (x == -1)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(x);

        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
    return NULL;
}

void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    TreeNode *temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    TreeNode *root = buildTree();

    TreeNode *answer = invertTree(root);
    printTree(answer);

    return 0;
}