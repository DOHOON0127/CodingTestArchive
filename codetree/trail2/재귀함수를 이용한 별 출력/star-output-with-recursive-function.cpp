#include <iostream>
using namespace std;

int N;

void printStar(int cnt) {
    if(cnt == 0) {
        return;
    }

    printStar(cnt - 1);

    for(int i = 0; i < cnt; i++) {
        cout << '*';
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    printStar(N);

    return 0;
}