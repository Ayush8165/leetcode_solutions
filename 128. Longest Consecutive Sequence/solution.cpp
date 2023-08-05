#include <bits/stdc++.h>
using namespace std;

void print(vector<int> temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 1;
    }
    if (nums.size() == 0)
    {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int answer = 1;
    int sum = 1;

    int i = 0, j = i + 1;
    while (i < j and j < nums.size())
    {
        if ((nums[j] - 1) == nums[j - 1])
        {
            int sum = j - i + 1;
            if (answer < sum)
            {
                answer = sum;
            }
            j++;
        }
        else if (nums[j] == nums[j - 1])
        {
            nums.erase(nums.begin() + j);
        }
        else
        {
            i = j;
            j = i + 1;
        }
    }
    return answer;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> temp;
    for (int j = 0; j < n; j++)
    {
        int input;
        cin >> input;
        temp.push_back(input);
    }

    cout << longestConsecutive(temp);

    return 0;
}