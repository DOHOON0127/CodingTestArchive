#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[100];

int max_sum = INT_MIN;

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = i+2; j < n; j++) {
            int temp_max = arr[i] + arr[j];

            max_sum = max(temp_max, max_sum);
        }
    }

    cout << max_sum;

    return 0;
}