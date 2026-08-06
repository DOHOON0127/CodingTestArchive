#include <iostream>
#include <climits> 
#define max_size 10001

using namespace std;

int n, k;
char arr[max_size];

int max_sum = INT_MIN;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int loc;
        char c;

        cin >> loc >> c;

        arr[loc] = c;
    }

    for(int i = 1; i <= max_size - k + 1; i++) {
        int sum = 0;
        for(int j = i; j <= i+k; j++) {

            if(arr[j] == 'G') {
                sum += 1;
            }
            else if(arr[j] == 'H') {
                sum += 2;
            }

        }
        max_sum = max(max_sum, sum);
    }

    cout << max_sum;


    return 0;
}