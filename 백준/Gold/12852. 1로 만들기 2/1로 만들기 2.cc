#include <bits/stdc++.h>
using namespace std;

// dp[X] = X를 1로 만드는 최소 연산 횟수
int dp[1000004];

int main()
{
    int N;

    cin >> N;

    dp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] =  dp[i-1] + 1;
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if ( i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }

    cout << dp[N] << '\n';

    vector<int> path;
    int x = N;
    while (x > 0)
    {
        path.push_back(x);
        if (x == 1) break;
        // dp[x] == dp[x/3] + 1 <- 실제로 3으로 나누는게 최적 경로였나?
        if (x % 3 == 0 && dp[x] == dp[x/3] + 1)
        {
            x = x / 3;
        }
        else if (x % 2 == 0 && dp[x] == dp[x/2] + 1)
        {
            x = x / 2;
        }
        else
        {
            x = x - 1;
        }
    }

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i != path.size() - 1) cout << " ";
    }
    cout << '\n';

    return 0;
}