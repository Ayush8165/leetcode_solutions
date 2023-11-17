#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    // uppercase to lower case
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < 91 and s[i] > 64)
        {
            s[i] = s[i] + 32;
        }
    }

    // removing spaces
    int i = 0;
    while (i < s.length())
    {
        if (!isalpha(s[i]) and !isdigit(s[i]))
        {
            s.erase(s.begin() + i);
            continue;
        }
        i++;
    }

    string rev = s;
    reverse(rev.begin(), rev.end());

    if (rev == s)
        return true;
    else
        return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s = "A man, a plan, a canal: Panama";

    bool answer = isPalindrome(s);
    cout << answer;

    return 0;
}