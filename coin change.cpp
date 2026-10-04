#include <iostream>
using namespace std;

int main()
{
    int n, amount;
    int coins[20];
    int dp[1000];

    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter amount: ";
    cin >> amount;

    // Initialize DP array
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = amount + 1;
    }

    dp[0] = 0;

    // Dynamic Programming
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    if (dp[amount] > amount)
        cout << "Amount cannot be formed";
    else
        cout << "Minimum number of coins = " << dp[amount];

    return 0;
}
