#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long rev = 0;
        while (x != 0)
        {
            rev = x % 10 + rev * 10;
            x = x / 10;
        }
        if (rev < INT_MIN or rev > INT_MAX)
        {
            return 0;
        }
        return rev;
    }
};