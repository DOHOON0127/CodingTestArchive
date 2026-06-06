#include <iostream>

using namespace std;

int N;

void solve(int cnt) {
    if(cnt == 0) {
        return;
    }

    solve(cnt-1);
    cout << "HelloWorld" << '\n';
}

int main() {
    cin >> N;

    solve(N);

    return 0;
}