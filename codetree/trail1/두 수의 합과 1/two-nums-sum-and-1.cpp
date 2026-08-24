#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int a, b;

    cin >> a >> b;

    int c = a + b;

    string str = to_string(c);

    int cnt = 0;
    for(char c : str) {
        if(c == '1') {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}