#include <iostream>
using namespace std;

int main() {
    // Please write your code here.

    string str;

    cin >> str;

    str[1] = 'a';
    str[(int)str.size()-2] = 'a';

    cout << str;
    return 0;
}