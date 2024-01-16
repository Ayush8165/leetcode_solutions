#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string answer = "";

        vector<int> integer{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> roman{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

        vector<int> index;

        while (num > 0)
        {
            // find next greater of the num
            int i = 0;
            for (i = 0; i < integer.size(); i++)
            {
                if (integer[i] > num)
                {
                    break;
                }
            }

            if (i == integer.size())
            {
                num = num - 1000;
                index.push_back(i);
                answer = answer + "M";
            }
            else
            {
                num = num - integer[i - 1];
                answer = answer + roman[i - 1];
            }
        }
        return answer;
    }
};

int main()
{
    Solution obj;
    cout << obj.intToRoman(43);
    return 0;
}