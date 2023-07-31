#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    vector<pair<int, int>> zeros;
    pair<int, int> sample;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                sample.first = i;
                sample.second = j;
                zeros.push_back(sample);
            }
        }
    }

    for (int i = 0; i < zeros.size(); i++)
    {
        int row = zeros[i].first;
        int column = zeros[i].second;

        // full row format
        for (int j = 0; j < matrix[row].size(); j++)
        {
            matrix[row][j] = 0;
        }

        // full col format
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[j][column] = 0;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;

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

    setZeroes(matrix);
    print(matrix);

    return 0;
}