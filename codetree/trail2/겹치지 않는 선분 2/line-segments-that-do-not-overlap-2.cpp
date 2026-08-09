#include <iostream>
using namespace std;

int n;
int x1[101];
int x2[101];
int arr[101];

bool isOverlap(int x1, int x2, int x3, int x4) { 
    if((x3 > x1) && (x4 < x2)) {
        return true;
    }

    if((x3 < x1) && (x4 > x2)) {
        return true;
    }

    return false;
    
}


// 4
// -3 4
// 7 8
// 10 16
// 3 9

int main() {

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> x1[i] >> x2[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(isOverlap(x1[i], x2[i], x1[j], x2[j])) {
                arr[i] += 1;
                arr[j] += 1;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(arr[i] == 0) {
            cnt++;
        }
    }

    cout << cnt;



    return 0;
}