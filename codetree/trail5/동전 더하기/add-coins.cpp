#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[10];

int main () {

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0; // 동전 갯수
    int temp = k; //나머지

    for(int i = n-1; i >= 0; i--) {
        cnt += temp / arr[i];
        temp = temp % arr[i]; 
    }

    cout << cnt;

    return 0;
}