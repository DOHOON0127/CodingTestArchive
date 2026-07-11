#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;

    cin >> str1 >> str2;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if((int)str1.size() != (int)str2.size()) {
        cout << "No";
        return 0;
    }

    for(int i = 0; i < (int)str2.size(); i++) {
        if(str1[i] != str2[i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";

    return 0;
}