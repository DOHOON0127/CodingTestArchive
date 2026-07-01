#include <iostream>
using namespace std;

int N;

int func(int cnt) {

    if(cnt % 2 == 0) {

        if(cnt == 2) {
            return 2;
        }

        return func(cnt-2) + cnt;

    }else{

        if(cnt == 1) {
            return 1;
        }

        return func(cnt-2) + cnt;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    cout << func(N);

    return 0;
}