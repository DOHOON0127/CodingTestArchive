#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arrA[100];
int arrB[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arrA[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> arrB[i];
    }

    sort(arrA, arrA+n);
    sort(arrB, arrB+n);

    bool isSame = true;
    for(int i = 0; i < n; i++) {
        if(arrA[i] != arrB[i]) {
            isSame = false;
        }
    }

    if(isSame) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }


    return 0;
}