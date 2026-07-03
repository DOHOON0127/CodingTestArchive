#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100];

int findMax(int a) {
    
    if(a == 0) {
        return arr[0];
    }

    return max(findMax(a-1), arr[a]);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findMax(n-1);
    // Please write your code here.

    return 0;
}