#include <bits/stdc++.h>
using namespace std;

string convoString(int n)
{
    string s;
    for (int i = 1; i <= n; i++)
    {
        char ch = i + 48;
        s = s + ch;
    }
    return s;
}

void solve(string s, int index, vector<string> &permutations)
{
    if (index == s.length())
    {
        permutations.push_back(s);
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        swap(s[i], s[index]);
        solve(s, index + 1, permutations);
        swap(s[i], s[index]);
    }
}

string getPermutation(int n, int k)
{
    string s = convoString(n);
    vector<string> permutations;
    int index = 0;
    solve(s, index, permutations);

    sort(permutations.begin(), permutations.end());

    if (permutations.size() != k)
    {
        k = k % permutations.size();
    }
    string answer = permutations[k - 1];
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    string answer = getPermutation(n, k);
    cout << answer;

    return 0;
}