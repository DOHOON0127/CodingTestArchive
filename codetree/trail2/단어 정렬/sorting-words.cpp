#include <iostream>
#include <algorithm>
using namespace std;

int n;
string arr[101];

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}