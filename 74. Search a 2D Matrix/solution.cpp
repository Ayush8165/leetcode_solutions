#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.size() == 0)
    {
        return false;
    }

    int n = matrix.size();
    int m = matrix[0].size();

    int s = 0;
    int e = (n * m) - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (matrix[mid / m][mid % m] == target)
        {
            return true;
        }
        if (matrix[mid / m][mid % m] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;

    int target;
    cin >> target;

    vector<vector<int>> matrix;
    vector<int> temp;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        matrix.push_back(temp);
        temp.clear();
    }
    cout << searchMatrix(matrix, target);
    return 0;
}