#include <bits/stdc++.h>
using namespace std;

int a, b, c; // 5 3 1
int A, B; // 1~6, 3~5, 2~6....
int arr[100];
int sum = 0;

int main() {
    cin >> a >> b >> c;

    for(int i = 0; i < 3; i++) {
        cin >> A >> B;
        for(int j = A-1; j < B-1; j++) {
            arr[j] += 1;
        }
    }

    for(int i = 0; i < 100; i++) {
        if(arr[i] == 1) {
            sum = sum + a*1;
        }
        else if(arr[i] == 2) {
            sum = sum + b*2;
        }
        else if(arr[i] == 3) {
            sum = sum + c*3;
        }
    }

    cout <<  sum << '\n';
}

