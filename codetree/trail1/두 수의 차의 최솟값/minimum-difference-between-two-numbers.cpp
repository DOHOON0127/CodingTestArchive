#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int arr[11];

int main() {

    int N;

    cin >> N;

    int max_val = INT_MAX;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N-1; i++) {
        int diff = abs(arr[i+1] - arr[i]);

        if(diff < max_val) {
            max_val = diff;
        }
    }

    cout << max_val;

    return 0;
}