#include <iostream>
using namespace std;

int main() {
    string arr[5] = {"apple", "banana", "grape", "blueberry", "orange"};
    char c;

    cin >> c;

    int cnt = 0;
    for(string str : arr) {
        if(str[2] == c || str[3] == c) {
            cout << str << '\n';
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}