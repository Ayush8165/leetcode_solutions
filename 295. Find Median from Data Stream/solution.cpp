#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        max.push(num);
        min.push(max.top());
        max.pop();

        if (min.size() > max.size())
        {
            max.push(min.top());
            min.pop();
        }
    }

    double findMedian()
    {
        if ((max.size() + min.size()) % 2 == 0)
        {
            double ans = (double)((min.top() + max.top()) / 2.0);
            return ans;
        }
        else
        {
            return max.top();
        }
    }
};