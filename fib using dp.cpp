#include <iostream>
using namespace std;

int main()
{
    int n;
    int dp[100];

    cout << "Enter N: ";
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "The " << n << "th Fibonacci number = " << dp[n];

    return 0;
}
