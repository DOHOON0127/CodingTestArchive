#include <iostream>
#include <string>

using namespace std;

int n;
string a;
string b;

void change(int loc) {
    for(int i = 0; i <= loc; i++) {
        if(a[i] == 'G') {
            a[i] = 'H';
        }
        else {
            a[i] = 'G';
        }
    }
}

bool isCorrect() {
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    cin >> a;
    cin >> b;

    int cnt = 0;

    for(int i = n-1; i >= 0; i--) {
        if(isCorrect()) break;

        if(a[i] != b[i]) {
            change(i);
            cnt++;
        }
    }


    cout << cnt;


    return 0;
}
