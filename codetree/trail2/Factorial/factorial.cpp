#include <iostream>

using namespace std;

int N;
int sum = 1;

int factorial(int cnt) {
    if(cnt == 0) {
        return 1;
    }

    sum = factorial(cnt - 1);

    return sum * cnt;
}

int main() {
    cin >> N;

    // Please write your code here.

    cout << factorial(N);

    return 0;
}