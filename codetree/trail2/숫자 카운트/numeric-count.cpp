#include <iostream>

using namespace std;

int n;
int a[10], b[10], c[10];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) 
        cin >> a[i] >> b[i] >> c[i];

    int cnt = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            for(int k = 1; k <= 9; k++) {

                if(i == j || j == k || k == i) {
                    continue;
                }

                bool isCorrect = true;

                for(int t = 0; t < n; t++) {
                    int first = a[t] / 100;
                    int second = (a[t] / 10) % 10;
                    int third = a[t] % 10;

                    int cnt1 = 0;
                    int cnt2 = 0;

                    if(first == i) {
                        cnt1++;
                    }
                    if(second == j) {
                        cnt1++;
                    }
                    if(third == k) {
                        cnt1++;
                    }

                    if(first == j || first == k) {
                        cnt2++;
                    }

                    if(second == i || second == k) {
                        cnt2++;
                    }

                    if(third == i || third == j) {
                        cnt2++;
                    }

                    // cout << cnt1 << ' ' << cnt2 << '\n';

                    if(b[t] != cnt1 || c[t] != cnt2) {
                        isCorrect = false;
                        break;
                    }
                   
                }

                if(isCorrect) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}