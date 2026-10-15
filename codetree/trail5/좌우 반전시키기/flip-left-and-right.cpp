#include <iostream>

using namespace std;

int n;
int arr[110];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = 0;

    for(int i = 0; i < n-1; i++) {

        if(arr[i] == 0) {
            arr[i] = 1;
            if(arr[i+1] == 0) {
                arr[i+1] = 1;
            }else {
                arr[i+1] = 0; 
            }

            if(arr[i+2] == 0) {
                arr[i+2] = 1;
            }else {
                arr[i+2] = 0;
            }
            cnt++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            cnt = -1;
        }
    }

    cout << cnt;

    return 0;
}
