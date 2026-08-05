#include <iostream>
#include <climits>
using namespace std;

int n,k;
int arr[100];
int max_sum = INT_MIN;

int main() {

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n-k+1; i++) {
        int sum = 0;

        for(int j = i; j < i+k; j++) {
            sum += arr[j]; 
            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum;


    return 0;
}