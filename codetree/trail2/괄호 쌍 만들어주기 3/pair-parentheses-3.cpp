#include <iostream>
using namespace std;

int main() {

    string a;

    cin >> a;

    int cnt = 0;


    for(int i = 0; i < (int)a.size(); i++) {
        for(int j = i+1; j < (int)a.size(); j++) {
            if(a[i] == ')') {
                break;
            }

            if(a[i] == '(' && a[j] == ')') {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}