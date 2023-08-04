#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int m, int n)
{
    // Base case
    if (i == m - 1 and j == n - 1)
    {
        return 1;
    }

    // Rejection Case
    if (i > m - 1 or j > n - 1)
    {
        return 0;
    }

    else
    {
        return solve(i + 1, j, m, n) + solve(i, j + 1, m, n);
    }
}

int uniquePaths(int m, int n)
{
    int answer = solve(0, 0, m, n);
    return answer;
}

// int uniquePaths(int m, int n)
// {
//     int N = n + m - 2;
//     int r = m - 1;
//     double res = 1;

//     for (int i = 1; i <= r; i++)
//     {
//         res = res * (N - r + i) / i;
//     }
//     return (int)res;
// }

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, n;
    cin >> m >> n;

    cout << uniquePaths(m, n);

    return 0;
}