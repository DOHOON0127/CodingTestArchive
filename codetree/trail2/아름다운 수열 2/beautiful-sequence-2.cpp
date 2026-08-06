#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int A[100];
int B[100];
int temp[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }

    int beauty_cnt = 0;

    if(m > n) {
        cout << beauty_cnt;
        return 0;
    }

    sort(B, B+m);

    for(int i = 0; i < n-m+1; i++) {

        for(int j = 0; j < m; j++) {
            temp[j] = A[i+j];
        }

        sort(temp, temp + m);

        bool isBeauty = true;
        for(int k = 0; k < m; k++) {
            if(temp[k] != B[k]) {
                isBeauty = false;
                break;
            }
        }

        if(isBeauty) {
            beauty_cnt++;
        }
    }

    cout << beauty_cnt;

    return 0;
}