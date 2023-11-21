#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int ans = 0;
    int left = 0, right = 0;
    map<char, int> freq;
    int maxfreq = 0;

    while (right < s.length())
    {
        freq[s[right]]++;
        maxfreq = max(maxfreq, freq[s[right]]);

        if ((right - left + 1 - maxfreq) <= k)
        {
            ans = max((right - left + 1), ans);
        }
        else
        {
            while ((right - left + 1 - maxfreq) > k and left <= right)
            {
                freq[s[left]]--;
                left++;
            }
        }
        right++;
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    int k;
    cin >> s >> k;

    cout << characterReplacement(s, k);

    return 0;
}