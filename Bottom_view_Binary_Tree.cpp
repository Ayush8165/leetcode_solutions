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

vector<int> bottomView(TreeNode *root)
{
    deque<pair<TreeNode *, int>> data;

    map<int, int> ans;

    int ln = 0, tln;
    TreeNode *troot = root;

    pair<TreeNode *, int> temp;
    temp.first = root;
    temp.second = ln;
    data.push_back(temp);

    while (data.empty() != true)
    {
        troot = data.front().first;
        tln = data.front().second;

        // push in map
        ans[tln] = troot->val;

        // push left root
        if (troot->left != NULL)
        {
            temp.first = troot->left;
            temp.second = tln - 1;
            data.push_back(temp);
        }

        // push right root
        if (troot->right != NULL)
        {
            temp.first = troot->right;
            temp.second = tln + 1;
            data.push_back(temp);
        }

        // pop
        data.pop_front();
    }

    vector<int> answer;
    for (auto it : ans)
    {
        answer.push_back(it.second);
    }
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}