#include <iostream>
using namespace std;
int k,n;
int arr[10][20];

int main() {
    cin >> k >> n;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            arr[i][j]--;
        }
    }
    // 개발자 번호를 순위가 높은 순서대로 나열한것
    // 4 1 2 3
    // 그냥 먼저 나오면 순위가 높은 것임
    // 3 4
    // 3 0 1 2
    // 3 0 2 1
    // 3 1 0 2

    int cnt = 0;

    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            if(a == b) continue;

            bool is_correct = true;

            for(int r = 0; r < k; r++) {
                int idx_a = 0;
                int idx_b = 0;
                
                for(int c = 0; c < n; c++) {
                    if(arr[r][c] == a) {
                        idx_a = c;
                    }
                    if(arr[r][c] == b) {
                        idx_b = c;
                    }
                }

                if(idx_a > idx_b) {
                    is_correct = false;
                }
            }

            if(is_correct) {
                cnt++;
            }

        }
    }

    cout << cnt;
    return 0;
}