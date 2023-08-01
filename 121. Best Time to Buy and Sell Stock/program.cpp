/* You are given an array prices where prices[i] is the price
of a given stock on the ith day.

You want to maximize your profit by choosing a single day to
buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int max = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            int temp = prices[j] - prices[i];
            if (temp > max)
            {
                max = temp;
            }
        }
    }

    if (max <= 0)
    {
        max = 0;
        return max;
    }
    else
    {
        return max;
    }
}

int maxProfit2(vector<int> &prices)
{
    int buy_index = -1;
    int sell_index = -1;
    int max = INT_MIN, min = INT_MAX;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
            buy_index = i;
        }
        if (prices[i] > max)
        {
            if (i > buy_index)
            {
                max = prices[i];
                sell_index = i;
            }
        }
    }

    if (sell_index == -1 or buy_index == -1)
    {
        return 0;
    }
    else
    {
        int temp = prices[sell_index] - prices[buy_index];
        return temp;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> prices;
    int temp;
    while (cin >> temp)
    {
        prices.push_back(temp);
    }
    int answer = maxProfit(prices);
    cout << answer;

    // maxProfit2(prices);

    return 0;
}