#include <iostream>
#include <unordered_map>
using namespace std;

int n,m;
unordered_map<int, int> M;

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        if (M.find(k) == M.end()) {
            M[k] = 1;
        }else {
            M[k] += 1;
        }
    }

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        if (M.find(k) != M.end()) {
            cout << M[k] << ' ';
        }else {
            cout << 0 << ' ';
        }

    }


    return 0;
}