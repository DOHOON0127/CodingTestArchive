#include <iostream>
using namespace std;

int N;

int solve(int cnt) {

    if(cnt == 1) {
        return 0;
    }

    if(cnt % 2 == 0) {
        return solve(cnt / 2) + 1;
    }
    else {
        return solve(cnt / 3) + 1;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << solve(N);

    return 0;
}