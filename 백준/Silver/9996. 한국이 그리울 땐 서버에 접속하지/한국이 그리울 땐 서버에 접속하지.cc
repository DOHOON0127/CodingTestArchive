#include <bits/stdc++.h>
using namespace std;

string a, str, st1, st2;
int N;

int main () {

    cin >> N;

    cin >> a;

    for(int i = 0; i < N; i++) {
        cin >> str;

        st1 = a.substr(0, a.find('*'));
        st2 = a.substr(a.find('*')+1);

        if(str.size() < st1.size() + st2.size()) {
            cout << "NE\n";
        }else{
            if(str.substr(0, st1.size()) == st1 && str.substr(str.size() - st2.size()) == st2) {
                cout << "DA\n";
            }else{
                cout << "NE\n";
            }
        }
    }
}