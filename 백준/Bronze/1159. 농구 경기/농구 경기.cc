#include <bits/stdc++.h>
using namespace std;

int N;
string s, str;
int arr[26];

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> s;
        arr[s[0] - 'a'] += 1;
    }   

    for(int i = 0; i < 26; i++) {
        if(arr[i] > 4) {
            str += i + 'a';
        }
    }

    if(str.size() != 0) {
        cout << str << '\n';
    }
    else {
        cout << "PREDAJA" << "\n";
    }
}

