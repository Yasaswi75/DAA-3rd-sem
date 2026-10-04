#include <iostream>
using namespace std;

int main()
{
    int n, sum;
    int a[50];
    bool dp[50][500];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter required sum: ";
    cin >> sum;

    // Initialize
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int j = 1; j <= sum; j++)
    {
        dp[0][j] = false;
    }

    // Dynamic Programming
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] ||
                            dp[i - 1][j - a[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[n][sum])
        cout << "Subset with given sum exists.";
    else
        cout << "Subset with given sum does not exist.";

    return 0;
}
