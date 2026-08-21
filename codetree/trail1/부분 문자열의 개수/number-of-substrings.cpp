#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    string a;
    string b; //2

    cin >> a >> b;

    int cnt = 0;
    for(int i = 0; i < (int)a.size() - 1; i++) {
        if(a.substr(i,2) == b) {
            cnt++;
        }
    } 

    cout << cnt;
    return 0;
}