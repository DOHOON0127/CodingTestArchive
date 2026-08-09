#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// 5 18
// 4
// 2
// 8
// 6
// 12

// 2 
// 4
// 6
// 8
// 12

// -> 4

int n, b;
int arr[1004];
int max_cnt = INT_MIN;

int main() {

    cin >> n >> b; // 학생수, 예산

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; i++) {
        arr[i] = arr[i] / 2;
        int sum = 0;
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            
                sum += arr[j];
                cnt++;

                if(sum > b) {
                    cnt--;
                    arr[i] = arr[i] * 2;
                    break;
                }
            


        }
        // cout << cnt << '\n';
        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt;

    return 0;
}