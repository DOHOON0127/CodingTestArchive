#include <bits/stdc++.h>
using namespace std;

long long dp[94];
int n;

int main ()
{
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= 94; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cin >> n;

    cout << dp[n] << '\n';
}