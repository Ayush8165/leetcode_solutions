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

void preorder(TreeNode *root, vector<int> &answer)
{
    if (root == NULL)
    {
        return;
    }

    // print root
    // cout << root->val << " ";
    answer.push_back(root->val);
    // got left
    preorder(root->left, answer);
    // go right
    preorder(root->right, answer);
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    TreeNode *tree = buildTree();

    vector<int> ans = preorderTraversal(tree);

    return 0;
}