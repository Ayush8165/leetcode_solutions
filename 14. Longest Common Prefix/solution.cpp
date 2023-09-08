#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    string smallest = strs[0];
    string largest = strs[strs.size() - 1];

    string prefix = "";

    for (int i = 0; i < min(smallest.length(), largest.length()); i++)
    {
        if (smallest[i] == largest[i])
        {
            prefix = prefix + smallest[i];
        }
        else
        {
            break;
        }
    }
    return prefix;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}