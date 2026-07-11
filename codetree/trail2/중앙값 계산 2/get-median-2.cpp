#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }



    for(int i = 0; i < n; i++) {
        sort(arr, arr + i+1);

        if(i % 2 == 0) {
            cout << arr[i / 2] << ' ';
        }
    }
    


    return 0;
}