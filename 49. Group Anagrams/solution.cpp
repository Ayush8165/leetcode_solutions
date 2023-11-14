#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<string> copy;
    copy = strs; // original vector copied and stored safe

    for (auto &it : strs)
    {
        sort(it.begin(), it.end());
    }

    // implement same elemnt tracker
    map<string, int> visited;
    vector<int> indexer;
    vector<vector<string>> answer;
    vector<string> sample;
    for (int i = 0; i < strs.size(); i++)
    {
        if (visited[strs[i]] != 0)
        {
            continue;
        }
        else
        {
            visited[strs[i]]++;
            indexer.push_back(i);
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (strs[j] == strs[i])
                {
                    // means pairing
                    indexer.push_back(j);
                }
            }
            for (auto it : indexer)
            {
                sample.push_back(copy[it]);
            }
            answer.push_back(sample);
            sample.clear();
            indexer.clear();
        }
    }
    return answer;
}