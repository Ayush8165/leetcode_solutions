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

void levelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> que;
    que.push(root);

    while (!que.empty())
    {
        int n = que.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *troot = que.front();
            if (troot->left != NULL)
            {
                que.push(troot->left);
            }
            if (troot->right != NULL)
            {
                que.push(troot->right);
            }
            cout << troot->val << " ";
            que.pop();
        }
        cout << endl;
    }
}

int heightTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = heightTree(root->left);
    int rh = heightTree(root->right);

    return 1 + max(lh, rh);
}

int solve(TreeNode *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = solve(root->left, maxi);
    int rh = solve(root->right, maxi);

    int dia = lh + rh;

    if (dia > maxi)
    {
        maxi = dia;
    }
    return max(lh, rh) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int maxi = 0;
    int dump = solve(root, maxi);
    return maxi;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    TreeNode *root = buildTree();
    // levelOrder(root);
    // cout << heightTree(root);
    cout << diameterOfBinaryTree(root);

    return 0;
}