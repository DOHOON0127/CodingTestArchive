#include <iostream>
using namespace std;

int main() {

    // 숫자로만 이루어진 문자열 a, b

    string a, b, c, d;

    cin >> a >> b;

    c = a + b;
    d = b + a;

    cout << stoi(c) + stoi(d);


    return 0;
}