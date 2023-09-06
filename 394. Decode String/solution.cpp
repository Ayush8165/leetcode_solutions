#include <bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
    string ans = "", substr = "", k;
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ']')
        {
            st.push(s[i]);
        }
        else
        {
            substr = "";
            while (st.top() != '[')
            {
                substr = st.top() + substr;
                st.pop();
            }
            st.pop();
            k = "";
            while (!st.empty() && isdigit(st.top()))
            {
                k = st.top() + k;
                st.pop();
            }
            for (int i = 0; i < stoi(k); i++)
            {
                for (int j = 0; j < substr.size(); j++)
                {
                    st.push(substr[j]);
                }
            }
        }
    }
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string input;
    cin >> input;

    cout << decodeString(input);

    return 0;
}