#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[2004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < 2*n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+2*n);

    int max_num = 0;

    for(int i = 0; i < n; i++) {
        int isMax = arr[i] + arr[2*n - 1 - i];

        if(isMax > max_num) {
            max_num = isMax;
        }
    }
    
    cout << max_num;

    // 최댓값을 최소로 만든다
    

    return 0;
}