#include <bits/stdc++.h>
using namespace std;

class timing
{
public:
    int start;
    int end;
    int pos;
};

bool comparator(timing d1, timing d2)
{
    if (d1.end < d2.end)
    {
        return true;
    }
    else if (d1.end > d2.end)
    {
        return false;
    }
    else if (d1.pos < d2.pos)
    {
        return true;
    }
}

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // creating and array of class object to store multiple data
    timing data[start.size()];
    for (int i = 0; i < start.size(); i++)
    {
        data[i].start = start[i];
        data[i].end = end[i];
        data[i].pos = i;
    }

    // sort meeting in order of end_time > position
    sort(data, data + start.size(), comparator);

    int last_end = data[0].end;
    vector<int> count;
    count.push_back(data[0].pos);

    for (int i = 1; i < start.size(); i++)
    {
        if (data[i].start > last_end)
        {
            count.push_back(data[i].pos);
            last_end = data[i].end;
        }
    }
    return count.size();
}