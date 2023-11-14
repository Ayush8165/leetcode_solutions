#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> counter;
    for (auto it : nums)
    {
        counter[it]++;
    }

    vector<pair<int, int>> cvector;
    for (auto it : counter)
    {
        cvector.push_back({it.first, it.second});
    }

    sort(cvector.begin(), cvector.end(), comp);

    vector<int> answer;
    for (auto it : cvector)
    {
        if (k > 0)
        {
            answer.push_back(it.first);
        }
        k--;
    }
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> nums = {3, 0, 1, 0};
    int k = 1;

    vector<int> answer = topKFrequent(nums, k);
    for (auto it : answer)
    {
        cout << it << " ";
    }

    return 0;
}