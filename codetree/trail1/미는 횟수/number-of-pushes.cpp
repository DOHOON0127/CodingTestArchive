#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    
    string a,b;

    cin >> a >> b;

    int n = 1;
    while(true) {
        a = a.substr((int)a.size()-1, 1) + a.substr(0, (int)a.size()-1);
        if(a == b) {
            break;
        }
        n++;

        if(n > a.size()) {
            n = -1;
            break;
        }
    }

    cout << n;
    return 0;
}