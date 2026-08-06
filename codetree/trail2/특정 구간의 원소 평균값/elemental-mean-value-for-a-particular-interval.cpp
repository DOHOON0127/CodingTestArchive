#include <iostream>
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

    int count_num = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }

            if(sum % (j-i+1) == 0) {
                int avg = sum / (j-i+1);

                for(int cnt = i; cnt <= j; cnt++) {
                    if(arr[cnt] == avg) {
                        count_num++;
                        break;
                    }
                }
            }
        }
    }

    cout << count_num;


    return 0;
}