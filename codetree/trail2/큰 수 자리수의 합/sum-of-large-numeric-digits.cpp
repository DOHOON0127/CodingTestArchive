#include <iostream>

using namespace std;

int a, b, c;

int sumEvery(int a) { 
    if(a / 10 == 0) {
        return a;
    }

    return sumEvery(a / 10) + (a % 10);
}

int main() {
    cin >> a >> b >> c;

    // Please write your code here.

    cout << sumEvery(a*b*c);

    return 0;
}