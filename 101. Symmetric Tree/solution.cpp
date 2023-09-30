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

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    queue<TreeNode *> que;
    que.push(root);
    vector<int> temp;
    vector<vector<int>> left;
    vector<vector<int>> right;

    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *troot = que.front();
            if (troot == NULL)
            {
                temp.push_back(-10);
                que.pop();
            }
            else
            {
                que.push(troot->left);
                que.push(troot->right);
                temp.push_back(troot->val);
                que.pop();
            }
        }
        left.push_back(temp);
        reverse(temp.begin(), temp.end());
        right.push_back(temp);
        temp.clear();
    }

    if (left == right)
    {
        return true;
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}