#include <iostream>
using namespace std;

int main() {

    string str[10];

    for(int i = 0; i < 10; i++) {
        cin >> str[i];
    }

    int sum_str = 0;
    for(int i = 0; i < 10; i++) {
        sum_str += (int)str[i].length();
    }

    cout << sum_str;

    return 0;
}