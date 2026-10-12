#include <iostream>
#include <climits>
using namespace std;

int n;
int a[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int partSum = 0;
    int maxPartSum = INT_MIN;

    // -1 -2 -3 -4

    for(int i = 0; i < n; i++) {
        partSum += a[i];
        if(partSum > 0) {
            maxPartSum = max(maxPartSum, partSum);
        }
        else {
            maxPartSum = max(maxPartSum, partSum);
            partSum = 0;
        }
    }

    cout << maxPartSum;

    return 0;
}
