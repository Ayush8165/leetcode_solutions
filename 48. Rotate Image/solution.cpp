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

// transpose and reverse technique
void rotate(vector<vector<int>> &matrix)
{
    // swapping elements above diagonal with the elements below diagonal, [i][j] with [j][i]
    for (int i = 0; i < matrix.size() - 1; i++)
    {
        for (int j = i + 1; j < matrix.size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // We transposed above, now we will reverse every row
    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m;
    cin >> m;

    vector<vector<int>> matrix;
    vector<int> sample;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            sample.push_back(temp);
        }
        matrix.push_back(sample);
        sample.clear();
    }

    rotate(matrix);
    print(matrix);

    return 0;
}