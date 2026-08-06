#include <iostream>
#include <climits>
#define max_loc 401
using namespace std;

int n,k;
int arr[max_loc];
int max_candy = INT_MIN;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int num, loc;

        cin >> num >> loc;

        if(arr[loc] != 0) {
            arr[loc] += num;
        }else {
            arr[loc] = num;
        }
    }

    for(int c = k; c < max_loc-k; c++) {
        int sum_candy = 0;
        for(int i = c-k; i <= c+k; i++) {
            sum_candy += arr[i];
        }
        max_candy = max(max_candy,sum_candy);
    }

    cout << max_candy;

    return 0;
}