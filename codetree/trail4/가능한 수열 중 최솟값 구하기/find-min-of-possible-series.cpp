#include <iostream>
using namespace std;

int n;
bool finished = false;

bool isValid(string s) {
    int len = (int)s.length();

    for(int i = 1; i <= len / 2; i++) {
        if(s.substr(len-i, i) == s.substr(len-2*i, i)) {
            return false;
        }
    }
    return true;
}

void solve(string s) {
    if(finished) return;

    if((int)s.length() == n) {
        cout << s;
        finished = true;
        return;
    }

    for(char c = '4'; c <= '6'; c++) {
        if(isValid(s+c)) {
            solve(s+c);
        }
    }


}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;


    solve("");
    
    return 0;
}