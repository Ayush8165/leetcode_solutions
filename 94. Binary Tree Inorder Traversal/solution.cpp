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

void inorder(TreeNode *root, vector<int> &answer)
{
    if (root == NULL)
    {
        return;
    }

    // go left
    inorder(root->left, answer);

    cout << root->val << " ";
    answer.push_back(root->val);

    // go right
    inorder(root->right, answer);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    TreeNode *tree = buildTree();
    vector<int> ans = inorderTraversal(tree);
    return 0;
}