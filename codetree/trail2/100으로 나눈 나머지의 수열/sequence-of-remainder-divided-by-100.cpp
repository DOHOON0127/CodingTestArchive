#include <iostream>
using namespace std;

int n;

int calc(int a) {
    if(a == 1) {
        return 2;
    }

    if(a == 2) {
        return 4;
    }

    return (calc(a-1) * calc(a-2)) % 100;
}

int main() {
    cin >> n;

    cout << calc(n);

    return 0;
}