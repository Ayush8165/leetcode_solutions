#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string countAndSay(int n)
{
    // base case
    if (n == 1)
    {
        return "1";
    }

    string ans;
    ans = countAndSay(n - 1);

    string answer = "";
    int count = 1;
    char curr;
    int i = 0;
    bool first = true;
    for (i = 0; i < ans.length(); i++)
    {
        if (first)
        {
            curr = ans[i];
            first = false;
        }
        else
        {
            if (ans[i] == curr)
            {
                count++;
            }
            else
            {
                char temp = count + '0';
                answer = answer + temp;
                answer = answer + curr;
                count = 1;
                curr = ans[i];
            }
        }
    }
    char temp = count + '0';
    answer = answer + temp;
    answer = answer + curr;

    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << countAndSay(n);

    return 0;
}