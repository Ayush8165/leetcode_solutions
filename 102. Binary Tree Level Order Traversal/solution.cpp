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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> answer;
    if (root == NULL)
    {
        return answer;
    }
    queue<TreeNode *> que;
    que.push(root);
    vector<int> temp;

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
            temp.push_back(troot->val);
            que.pop();
        }
        answer.push_back(temp);
        temp.clear();
    }
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}