#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    unordered_map<TreeNode *, TreeNode *> um;
    unordered_set<TreeNode *> visited;

    void connect_parent(TreeNode *root, TreeNode *parent)
    {
        if (root == NULL)
        {
            return;
        }
        um[root] = parent;
        connect_parent(root->left, root);
        connect_parent(root->right, root);
    }

    void dfs(TreeNode *target, int k, vector<int> &ans)
    {
        if (target == NULL or visited.count(target) == 1)
        {
            return;
        }

        visited.insert(target);
        if (k == 0)
        {
            ans.push_back(target->val);
        }
        dfs(target->left, k - 1, ans);
        dfs(target->right, k - 1, ans);
        dfs(um[target], k - 1, ans);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        connect_parent(root, NULL);
        dfs(target, k, ans);
        return ans;
    }
};
