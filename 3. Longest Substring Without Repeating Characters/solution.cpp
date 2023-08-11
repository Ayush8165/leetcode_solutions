#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int len = 0;
    map<char, int> mpp;
    int left = 0;
    int right = 0;

    while (left <= right and right < s.length())
    {
        if (mpp[s[right]] == 0)
        {
            mpp[s[right]]++;
            len = max(len, right - left + 1);
            right++;
            // cout << "1 ";
        }
        else
        {
            // cout << "2 ";
            while (mpp[s[right]] != 0)
            {
                mpp.erase(s[left]);
                left++;
                // cout << "3 ";
            }
        }
    }
    return len;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s);

    // map<char, int> mpp;
    // for (int i = 0; i < s.length(); i++)
    // {
    //     mpp[s[i]]++;
    // }

    // // mpp.erase('b');

    // for (auto x : mpp)
    // {
    //     cout << x.first << " , " << x.second << endl;
    // }

    // cout << mpp[s[2]];

    return 0;
}