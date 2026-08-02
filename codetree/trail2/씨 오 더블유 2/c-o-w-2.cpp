#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int cnt;

int main() {
    cin >> n;
    cin >> str;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(str[i] == 'C' &&
                str[j] == 'O' && str[k] == 'W') {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}