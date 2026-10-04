#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[100];
    int dp[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i] = 1;
    }

    // Dynamic Programming
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                if (dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }

    int maximum = dp[0];

    for (int i = 1; i < n; i++)
    {
        if (dp[i] > maximum)
            maximum = dp[i];
    }

    cout << "Length of Longest Increasing Subsequence = "
         << maximum;

    return 0;
}
