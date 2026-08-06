#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int n,h,t;
int arr[101];

int min_cost = INT_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> t;

    // h와 동일한 높이를 가진 애들이 t개 이상 연속되도록 나와야함

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int diff = 0;

            for(int k = i; k <= j; k++) {
                
                if(j - i + 1 >= t) {
                    
                    if(arr[k] != h) {
                        diff = diff + abs(h - arr[k]);
                    }
                }

            }

            if(diff != 0) {
             min_cost = min(min_cost, diff);

            }

        }

    }

    cout << min_cost;

    return 0;
}