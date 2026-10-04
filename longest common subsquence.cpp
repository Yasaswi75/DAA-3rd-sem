#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100], str2[100];
    int dp[100][100];

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    int m = strlen(str1);
    int n = strlen(str2);

    // Initialize first row and column
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    // Dynamic Programming
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << "Length of Longest Common Subsequence = "
         << dp[m][n];

    return 0;
}
