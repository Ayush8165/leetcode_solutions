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

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < intervals.size(); j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }

    // for (int i = 0; i < intervals.size() - 1; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         if (intervals[i][1] >= intervals[i + 1][0])
    //         {
    //             intervals[i][1] = intervals[i + 1][1];
    //         }
    //     }
    // }

    // for (int i = 0; i < intervals.size() - 1; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         if (intervals[i][1] == intervals[i + 1][1])
    //         {
    //             intervals.erase(intervals.begin() + i + 1);
    //         }
    //     }
    // }

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> intervals;
    vector<int> sample;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int temp;
            cin >> temp;
            sample.push_back(temp);
        }
        intervals.push_back(sample);
        sample.clear();
    }

    vector<vector<int>> answer = merge(intervals);
    print(answer);

    return 0;
}