#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int n, m;
unordered_map<string, int> M;
string arr[100000];
int max_num = INT_MIN;

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        M[arr[i]] = i+1;
    }

    for (int i = 0; i < m; i++) {
        string a;

        cin >> a;

        if ( '0' <= a[0] && a[0] <= '9') {
            cout << arr[stoi(a)-1] << '\n';
        }
        else {
            cout << M[a] << '\n';
        }
    }



    return 0;
}