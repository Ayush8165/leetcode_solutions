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

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> tri;
    vector<int> sample;
    vector<int> memory;
    for (int i = 0; i < numRows; i++)
    {
        sample.push_back(1);
        if (i > 0)
        {
            for (int j = 0; j < i - 1; j++)
            {
                int temp = memory[j] + memory[j + 1];
                sample.push_back(temp);
            }
            sample.push_back(1);
        }
        tri.push_back(sample);
        memory = sample;
        sample.clear();
    }
    return tri;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int row;
    cin >> row;

    vector<vector<int>> answer = generate(row);
    print(answer);
    return 0;
}