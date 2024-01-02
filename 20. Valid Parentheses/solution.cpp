#include <bits/stdc++.h>
using namespace std;

stack<char> st;

class Solution
{
public:
    void printStack(stack<char> st)
    {
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }

    bool isValid(string s)
    {
        stack<char> st;
        map<char, char> mpp;
        mpp['{'] = '}';
        mpp['('] = ')';
        mpp['['] = ']';

        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (mpp[st.top()] != 0)
                {
                    if (s[i] == mpp[st.top()])
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
            }
        }
        if (st.empty())
            return true;

        return false;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s = "{{{[()]}}}";
    Solution obj;

    bool flag = obj.isValid(s);
    cout << flag;

    return 0;
}