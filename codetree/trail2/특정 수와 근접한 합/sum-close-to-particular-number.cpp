#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int n, s;
int arr[100];
int T_S = INT_MAX;

int sum_arr(const int arr[]) {

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int T = sum_arr(arr) - arr[i] - arr[j];

            T_S = min(T_S, abs(T-s));
        }
    }

    cout << T_S;

    return 0;
}