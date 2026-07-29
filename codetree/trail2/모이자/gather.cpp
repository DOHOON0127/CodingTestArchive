#include <iostream>
#include <climits>
// #include <cmath>
using namespace std;

int N;
int arr[100];
int min_sum = INT_MAX;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        int sum = 0;

        for(int j = 0; j < N; j++) {
            sum += abs(i-j) * arr[j];
        }

        if(min_sum > sum) {
            min_sum = sum;
        }
    }

    cout << min_sum;


    return 0;
}