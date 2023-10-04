#include <bits/stdc++.h>
using namespace std;

void analyse(vector<int> &temp)
{
    if (temp.empty())
    {
        return;
    }

    while (temp[0] == -1)
    {
        temp.erase(temp.begin());
    }

    reverse(temp.begin(), temp.end());
    while (temp[0] == -1)
    {
        temp.erase(temp.begin());
    }
    reverse(temp.begin(), temp.end());
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> v;
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(10);
    v.push_back(3);
    v.push_back(-1);
    v.push_back(5);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);

    analyse(v);

    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}