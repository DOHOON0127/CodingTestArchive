#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;

    map<int, int> M;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> num;

        M.insert({num, i}); 
    }

    map<int, int>::iterator it;
    for(it = M.begin(); it != M.end(); it++) {
        cout << it->first << " " << it->second << '\n';
    }

    return 0;
}