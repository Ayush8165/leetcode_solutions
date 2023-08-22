#include <bits/stdc++.h>
using namespace std;

void print(vector<int> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << matrix[i] << " ";
    }
    cout << endl;
}

int trap(vector<int> &height)
{
    int level = 0;

    vector<int> lefts;
    vector<int> rights;

    int max = INT_MIN;
    for (int i = 0; i < height.size(); i++)
    {
        if (max < height[i])
        {
            max = height[i];
        }
        lefts.push_back(max);
    }

    max = INT_MIN;
    for (int i = height.size() - 1; i >= 0; i--)
    {
        if (max < height[i])
        {
            max = height[i];
        }
        rights.push_back(max);
    }
    reverse(rights.begin(), rights.end());

    for (int i = 0; i < height.size(); i++)
    {
        level = level + min(rights[i], lefts[i]) - height[i];
    }

    return level;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
        int input;
        cin >> input;
        temp.push_back(input);
    }

    cout << trap(temp);
    return 0;
}