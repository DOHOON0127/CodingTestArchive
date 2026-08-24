#include <iostream>
using namespace std;

int main() {
    // Please write your code here.

    int n;
    string a;

    cin >> n >> a;
    string str;
    int cnt =0;
    for(int i = 0; i < n; i++) {
        cin >> str;

        if(str == a) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}