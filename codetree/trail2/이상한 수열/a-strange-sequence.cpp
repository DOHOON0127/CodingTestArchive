#include <iostream>

using namespace std;

int N;

int findN(int a) {

    if(a == 1) {
        return 1;
    }

    if(a == 2) {
        return 2;
    }

    return findN(a / 3) + findN(a - 1);

}

int main() {
    cin >> N;

    cout << findN(N);

    return 0;
}