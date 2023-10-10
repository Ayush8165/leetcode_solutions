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

// 2i+1 and 2i+2

int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, long long>> que;
    que.push({root, 1});
    long long lvlmin = 1;
    int lft, rht;
    int ans = 0;

    while (!que.empty())
    {
        int count = que.size();
        lvlmin = que.front().second;
        for (int i = 0; i < count; i++)
        {
            TreeNode *troot = que.front().first;
            long long tval = que.front().second;
            que.pop();
            if (i == 0)
            {
                lft = tval;
            }
            if (i == count - 1)
            {
                rht = tval;
            }
            if (troot->left)
            {
                que.push({troot->left, 2 * (tval - lvlmin) + 1});
            }
            if (troot->right)
            {
                que.push({troot->right, 2 * (tval - lvlmin) + 2});
            }
        }
        ans = max(rht - lft + 1, ans);
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}