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


    sort(arr, arr+n);

    vector<string> V;
    
    for(int i = 0; i < n; i++) {
        bool isMatch = true;
        
        for(int j = 0; j < (int)t.size(); j++) {
            if(arr[i][j] != t[j]) {
                isMatch = false;
            }
        }

        if(isMatch) {
            V.push_back(arr[i]);
        }

    }

    cout << V[k-1];




    return 0;
}