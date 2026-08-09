#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int n;
int start_t[100];
int end_t[100];
int arr[1004];
int max_time = INT_MIN;

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> start_t[i] >> end_t[i];
    }

    for(int i = 0; i < n; i++) {
        memset(arr, 0, sizeof(arr));
        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            for(int k = start_t[j]; k < end_t[j]; k++) {
                arr[k] += 1;
            }
            
        }

        int cnt = 0;
        for(int c = 0; c < 1004; c++) {
            if(arr[c] > 0) {
                cnt++;
            }
        }

        max_time = max(max_time, cnt);

    }

    cout << max_time;

    return 0;
}