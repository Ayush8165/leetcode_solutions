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
        pair<char, char> br[3];
        br[0] = make_pair('{', '}');
        br[1] = make_pair('(', ')');
        br[2] = make_pair('[', ']');

        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                for (auto it : br)
                {
                    if (it.first == s[i])
                    {
                        st.push(s[i]);
                        goto done;
                    }
                }
                return false;
            }
            else
            {
                for (auto it : br)
                {
                    if (it.first == s[i])
                    {
                        st.push(s[i]);
                        goto done;
                    }
                }
                for (auto it : br)
                {
                    if (it.second == s[i])
                    {
                        if (it.first == st.top())
                        {
                            st.pop();
                            goto done;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        done:
            continue;
        }

        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
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