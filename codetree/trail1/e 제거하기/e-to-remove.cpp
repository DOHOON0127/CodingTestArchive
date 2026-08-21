#include <iostream>
using namespace std;

int main() {
    // Please write your code here.

    string str;

    cin >> str;

    if(str.find('e') != string::npos) {
        str.erase(str.find('e'), 1);
    }
    cout << str;
    return 0;
}