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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> v;
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(5);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);
    
    for (auto it : v)
    {
        cout << it << " ";
    }

    return 0;
}