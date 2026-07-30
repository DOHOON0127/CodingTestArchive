#include <iostream>
#include <climits>
using namespace std;

int n, m;
int arr[50][50];
int dp[50][50];

void initialize() {

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][0] = 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    initialize();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int p = 0; p < i; p++) {
                for(int q = 0; q < j; q++) {

                    if(arr[i][j] > arr[p][q]) {
                        
                        if(dp[p][q] == INT_MIN) {
                            continue;
                        }

                        dp[i][j] = max(dp[i][j], dp[p][q]+1);
                        

                    }
                }
            }
        }
    }

    int max_num = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dp[i][j] > max_num) {
                max_num = dp[i][j];
            }
        }
    }

    cout << max_num;


    return 0;
}
