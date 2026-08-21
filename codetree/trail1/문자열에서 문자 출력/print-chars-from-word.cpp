#include <iostream>
using namespace std;

string str;

int main() {

    cin >> str;

    for(auto c : str) {
        cout << c << '\n';
    }

    return 0;
}