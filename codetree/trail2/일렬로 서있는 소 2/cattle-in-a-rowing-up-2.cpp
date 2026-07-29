#include <iostream>
using namespace std;

int arr[100];

int main() {

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(arr[k] >= arr[j] && arr[j] >= arr[i]) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;
    
    return 0;
}