#include <iostream>
#include <climits>
using namespace std;

int n, m;
int arr[5][5];
int check[5][5];

void make_zero() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            check[i][j] = 0;
        }
    }
}

void fill_check(int r1, int c1, int r2, int c2) {
    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            check[i][j]++;
        }
    }
}

bool check_over() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(check[i][j] >= 2) {
                return true;
            }
        }
    }
    return false;
}

bool isOverlap(int r1, int c1, int r2, int c2, int r3, int c3, int r4, int c4) {
    make_zero();
    fill_check(r1, c1, r2, c2);
    fill_check(r3, c3, r4, c4);

    return check_over();
}

int rectSum(int r1, int c1, int r2, int c2) {
    int sum = 0;
    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

int findMaxSum(int r1, int c1, int r2, int c2) {
    int max_sum = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = i; k < n; k++) {
                for(int l = j; l < m; l++) {
                    if(!isOverlap(r1, c1, r2, c2, i, j, k, l)) {
                        max_sum = max(max_sum, rectSum(r1,c1,r2,c2) + rectSum(i,j,k,l));
                    }
                }
            }
        }
    }

    return max_sum;
}

int findMaxSum() {
    int max_sum = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = i; k < n; k++) {
                for(int l = j; l < m; l++) {
                    max_sum = max(max_sum, findMaxSum(i,j,k,l));
                }
            }
        }
    }

    return max_sum;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = findMaxSum();

    cout << ans;

    

    return 0;
}