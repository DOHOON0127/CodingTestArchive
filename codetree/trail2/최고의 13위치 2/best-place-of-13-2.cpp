#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[20][20];
int max_coin = INT_MIN;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int p = 0; p < n; p++) {

        for(int i = 0; i+2 < n; i++) {

            int sum = arr[p][i] + arr[p][i+1] + arr[p][i+2];

            for(int k = 0; k < n; k++) {
                
                for(int j = 0; j+2 < n; j++) {
                    if(p == k && j < i+3 ) {
                        continue;
                    }
                    int sum1 = arr[k][j] + arr[k][j+1] + arr[k][j+2];

                    max_coin = max(max_coin, sum+sum1);
                }
            }
        
        }
    }

    cout << max_coin;
    

    return 0;
}