#include <iostream>
#include <climits>
using namespace std;

int min_diff = INT_MAX;
int arr[6];

int getDiff(int i, int j, int k) {
    int sum_arr = 0;

    for(int q = 0; q < 6; q++) {
        sum_arr += arr[q];
    }

    return abs(sum_arr - 2*(arr[i] + arr[j] + arr[k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < 6; i++) {
        for(int j = i+1; j < 6; j++) {
            for(int k = j+1; k < 6; k++){
                min_diff = min(min_diff, getDiff(i,j,k));
            }
        }
    }

    cout << min_diff;

    return 0;
}