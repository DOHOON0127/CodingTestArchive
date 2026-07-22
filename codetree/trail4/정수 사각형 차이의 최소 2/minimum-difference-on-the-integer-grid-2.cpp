#include <iostream>
#include <climits>
using namespace std;

int N;
int arr[100][100];
int dp[100][100];
int ans = INT_MAX;

void Initialize() {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
           dp[i][j] = INT_MAX;
        }
    }

    dp[0][0] = arr[0][0];

    for(int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i-1][0], arr[i][0]);
    }

    for(int i = 1; i < N; i++) {
        dp[0][i] = max(dp[0][i-1], arr[0][i]);
    }

}

int Solve(int lower_bound) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] < lower_bound) {
                arr[i][j] = INT_MAX;
            }
        }
    }    

    Initialize();

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), arr[i][j]);
        }
    }

    return dp[N-1][N-1]; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

   for(int lower_bound = 1; lower_bound <= 100; lower_bound++) {   
        int upper_bound = Solve(lower_bound);

        if(upper_bound == INT_MAX) {
            continue;
        }

        ans = min(ans, upper_bound - lower_bound);
   }

    cout << ans;

    return 0;
}