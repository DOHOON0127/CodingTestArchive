#include <iostream>
#include <climits>
using namespace std;

int arr[20][20];

int main() {
    int n;

    cin >> n;

    int max_cnt = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-2; j++) {

            int max_coin = max(max_cnt, arr[i][j] + arr[i][j+1] + arr[i][j+2]);
            max_cnt = max_coin;
            
        }
    }

    cout << max_cnt;

    return 0;
}