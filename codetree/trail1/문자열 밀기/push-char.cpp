#include <iostream>
using namespace std;

int main() {
    string str;

    cin >> str;

    int n = str.size();

    cout << str.substr(1, n-1) + str.substr(0,1);

    return 0;
}