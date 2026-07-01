#include <iostream>

using namespace std;

int N;

void printN(int cnt) {
    if(cnt == 0) {
        return;
    }

    cout << cnt << ' ';

    printN(cnt-1);

    cout << cnt << ' ';


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // Please write your code here.
    printN(N);

    return 0;
}