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
    string number = convoString(n);
    string answer = "";

    // k-- for 0 indexing
    k--;

    // get factorial
    int a = factorial(number.length());
    a = a / number.length();

    while (1)
    {
        int index = k / a;
        answer = answer + number[index];
        number.erase(index, 1);
        if (number.length() <= 0)
        {
            break;
        }
        k = k % a;
        a = a / number.length();
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