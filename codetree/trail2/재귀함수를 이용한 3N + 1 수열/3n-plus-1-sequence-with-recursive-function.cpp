#include <iostream>

using namespace std;

int n, cnt;

int countOne(int a) {
    if(a == 1) {
        return 1;
    }

    if(a % 2 == 0) {
        cnt++;
        return countOne(a / 2);
    }
    else {
        cnt++;
        return countOne(a * 3 + 1);
    }
}

int main() {
    cin >> n;

    // Please write your code here.

    countOne(n);

    cout << cnt;

    return 0;
}