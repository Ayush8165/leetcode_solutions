#include <iostream>
#include <climits>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int arr[n];
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    int freq[max + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0; i < max + 1; i++)
    {
        if (freq[i] > 0)
        {
            if (freq[i] % 2 == 0)
            {
                /* code */
            }
        }
    }

    // i = 0;
    // int temp = 0;
    // bool flag;
    // while (1)
    // {
    //     i = 0;
    //     flag = true;
    //     while (i < n - 1)
    //     {
    //         if (arr[i] > arr[i + 1])
    //         {
    //             temp = arr[i];
    //             arr[i] = arr[i + 1];
    //             arr[i + 1] = temp;
    //             flag = false;
    //             break;
    //         }
    //         i++;
    //     }
    //     if (flag == true)
    //     {
    //         break;
    //     }
    // }

    int pair = n / 2;
    int count = 0;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum = sum + arr[i - 1];
        count++;
        i--;
        if (count == pair)
        {
            break;
        }
    }
    cout << sum;

    return 0;
}