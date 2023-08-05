#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;

    // sort to avoid duplicates
    sort(nums.begin(), nums.end());

    // it is basically concept of 4 loops into 3 loop (2 normal and 1 two pointer while loop) but just avoiding same values of element when same pointer shifts. this whill help in avoiding same answers and reduce no of operations
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 and nums[i] == nums[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j != i + 1 and nums[j] == nums[j - 1])
            {
                continue;
            }
            int k = j + 1;
            int l = nums.size() - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum = sum + nums[j];
                sum = sum + nums[k];
                sum = sum + nums[l];

                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while (k < l and nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                    while (k < l and nums[l] == nums[l + 1])
                    {
                        l--;
                    }
                }
                else if (sum < target)
                {
                    k++;
                    while (k < l and nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                }
                else
                {
                    l--;
                    while (k < l and nums[l] == nums[l + 1])
                    {
                        l--;
                    }
                }
            }
        }
    }
    return ans;
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

    int target;
    cin >> target;

    vector<vector<int>> answer = fourSum(temp, target);
    print(answer);

    return 0;
}