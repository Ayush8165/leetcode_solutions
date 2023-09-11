#include <bits/stdc++.h>
using namespace std;

vector<int> stringToVector(string version1)
{
    vector<int> v1;
    int num = 0;
    for (int i = 0; i < version1.length(); i++)
    {
        if (version1[i] == '.')
        {
            v1.push_back(num);
            num = 0;
        }
        else
        {
            num = num * 10 + (version1[i] - '0');
        }
    }
    v1.push_back(num);

    return v1;
}

int compareVersion(string version1, string version2)
{
    vector<int> v1 = stringToVector(version1);
    vector<int> v2 = stringToVector(version2);

    bool change = false;
    // we need v1 to be bigger
    if (v1.size() < v2.size())
    {
        swap(v1, v2);
        change = true;
    }

    int i = 0, j = 0;
    while (i != v1.size() and j != v2.size())
    {
        if (v1[i] > v2[j])
        {
            if (change)
            {
                return -1;
            }
            return 1;
        }
        else if (v1[i] < v2[j])
        {
            if (change)
            {
                return 1;
            }
            return -1;
        }
        else
        {
            i++, j++;
        }
    }

    if (i != v1.size())
    {
        while (i != v1.size())
        {
            if (v1[i] != 0)
            {
                if (change)
                {
                    return -1;
                }
                return 1;
            }
            i++;
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string version1, version2;
    cin >> version1 >> version2;
    cout << compareVersion(version1, version2);
    return 0;
}