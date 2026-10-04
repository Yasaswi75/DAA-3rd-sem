#include <iostream>
using namespace std;

int main()
{
    int n, capacity;
    int weight[20], value[20];
    int dp[20][100];

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
        cin >> value[i];

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Initialize first row and column
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    // Dynamic Programming
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
            {
                if (value[i - 1] + dp[i - 1][w - weight[i - 1]]
                    > dp[i - 1][w])
                {
                    dp[i][w] = value[i - 1]
                              + dp[i - 1][w - weight[i - 1]];
                }
                else
                {
                    dp[i][w] = dp[i - 1][w];
                }
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value = " << dp[n][capacity];

    return 0;
}
