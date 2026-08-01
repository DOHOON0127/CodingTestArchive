#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
int arr[200][200];
int max_sum = INT_MIN;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m-2; j++) {

            int sum = 0;
            
            for(int k = j; k < j+3; k++) {
                sum += arr[i][k];
            }

            max_sum = max(sum, max_sum);
        }
    }


    for(int i = 0; i < n-2; i++) {
        for(int j = 0; j < m; j++) {

            int sum = 0;
            
            for(int k = i; k < i+3; k++) {
                sum += arr[k][j];
            }

            max_sum = max(sum, max_sum);
        }
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {

            int square_sum = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1];

            max_sum = max(square_sum - arr[i][j], max_sum);
            max_sum = max(square_sum - arr[i+1][j], max_sum);
            max_sum = max(square_sum - arr[i][j+1], max_sum);
            max_sum = max(square_sum - arr[i+1][j+1], max_sum);

        }
    }

    cout << max_sum;



    return 0;
}