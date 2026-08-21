#include <iostream>
using namespace std;

int main() {
    string A;
    string B;

    cin >> A >> B;
    string nw, nw1;

    nw = A+B;
    nw1 = B+A;

    if(nw == nw1) {
        cout << "true";
    }
    else {
        cout << "false";
    }
    return 0;
}