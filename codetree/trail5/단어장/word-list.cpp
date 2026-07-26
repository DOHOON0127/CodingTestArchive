#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;

    cin >> n;

    map<string, int> M;

    for(int i = 0; i < n; i++) {
        cin >> str;

        if(M.find(str) != M.end()) {
            M[str] += 1;
        }
        else {
            M[str] = 1;
        }
    }

    map<string, int>::iterator it;
    for(it = M.begin(); it != M.end(); it++) {
        cout << it->first << " " << it->second << '\n';
    }

    return 0;
}