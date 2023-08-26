#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    vector<string> words;
    string temp = "";
    temp = temp + s[0];
    for (int i = 1; i < s.length(); i++)
    {
        // beakpoints
        // space after word
        if (s[i] == ' ' and s[i - 1] != ' ')
        {
            words.push_back(temp);
            temp.clear();
            temp = temp + s[i];
            continue;
        }

        // word after space
        if (s[i] != ' ' and s[i - 1] == ' ')
        {
            words.push_back(temp);
            temp.clear();
            temp = temp + s[i];
            continue;
        }
        temp = temp + s[i];
    }
    words.push_back(temp);

    reverse(words.begin(), words.end());

    string final = "";
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i][0] == ' ')
        {
            final = final + ' ';
            continue;
        }
        final = final + words[i];
    }

    while (final[0] == ' ')
    {
        final.erase(0, 1);
    }
    while (final[final.length() - 1] == ' ')
    {
        final.pop_back();
    }

    return final;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s = "the sky   is blue";
    string answer = reverseWords(s);
    cout << answer;

    return 0;
}