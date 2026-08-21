#include <iostream>
using namespace std;

int main() {
    // Please write your code here.

    string str;

    cin >> str;

    for(int i = 2; i < (int)str.size(); i++) {
        if(str[i] == str[1]) {
            str[i] = str[0];
        }
    }
    str[1] = str[0];

    cout << str;

    return 0;
}