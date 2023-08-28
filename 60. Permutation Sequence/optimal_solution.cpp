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

int factorial(int n)
{
    int ans = 1;
    while (n != 0)
    {
        ans = ans * n;
        n--;
    }
    return ans;
}

string getPermutation(int n, int k)
{
    string s = convoString(n);
    string answer = "";
    k--;
    
    while (true)
    {
        int x = s.length() - 1;
        int fact = factorial(x);
        answer = answer + s[k / fact];
        k = k % fact;
        cout << s << endl;
        cout << k / fact;
        s.erase(k / fact, 1);
        cout << s << endl;
        if (s.length() == 0)
        {
            break;
        }
    }
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