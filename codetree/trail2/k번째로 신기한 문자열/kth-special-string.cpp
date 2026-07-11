#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
string t;
string arr[100];

int main() {
    cin >> n >> k >> t;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<string> V;
    
    for(int i = 0; i < n; i++) {
        bool isMatch = true;

        if (arr[i].size() < t.size()) {
            continue;
        }

        if(arr[i].substr(0, t.size()) == t) {
            V.push_back(arr[i]);
        }
    }

    sort(V.begin(), V.end());

    cout << V[k-1];




    return 0;
}