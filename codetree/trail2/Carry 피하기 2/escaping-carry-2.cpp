#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[20];
int max_sum = INT_MIN;


bool isCarry(int a, int b, int c) {

    while(a != 0 || b != 0 || c != 0) {

        int sum = 0;

        sum += a % 10 + b % 10 + c % 10;

        a = a / 10;
        b = b / 10;
        c = c / 10;

        if(sum >= 10) {
            return true; // carry 발생
        }

    }

    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                if(!isCarry(arr[i], arr[j], arr[k])) {
                    int sum = arr[i]+arr[j]+arr[k];
                    max_sum = max(sum, max_sum);
                }
            }
        }
    }

    if(max_sum == INT_MIN) {
        cout << -1;
    }
    else{
       cout << max_sum;
    }




    return 0;
}