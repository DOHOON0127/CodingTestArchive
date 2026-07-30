#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
pair<int, int> p[1000];
int dp[1000];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;

        p[i] = make_pair(x1, x2);
    }

    sort(p, p+n);

    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            int x_1;
            tie(x_1, ignore) = p[i];

            int x_2;
            tie(ignore, x_2) = p[j];

            if(x_2 < x_1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}