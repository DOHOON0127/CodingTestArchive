#include <iostream>
using namespace std;

int n;
int arr[11];

// 최대공약수를 먼저 구하기
// a,b의 최대공약수를 구하는 함수 maxNum
int maxNum(int a, int b) {
    if(b == 0) {
        return a;
    }
    return maxNum(b, (a % b));
}

// 최소공배수를 구하는 함수
// 최소공배수는 a * b를 최대공약수로 나눠주면 됨
int solve(int a, int b) {

    return ((a * b) / maxNum(a, b));

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if(n == 1) {
        cout << arr[0];
        return 0;
    }

    int temp = solve(arr[0], arr[1]);

    for(int j = 2; j < n; j++) {
        temp = solve(temp, arr[j]);
    }

    cout << temp;

    return 0;
}