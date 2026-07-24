#include <iostream>
using namespace std;

int n, m;
int arr[100][100];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int r,c;

    for(int i = 0; i < m; i++) {
        cin >> r >> c;

        r--;
        c--;

        arr[r][c] = 1;
        
        int cnt = 0;

        for(int j = 0; j < 4; j++) {
            int nr = r + dr[j];
            int nc = c + dc[j];

            if(inRange(nr, nc) && arr[nr][nc] == 1) {
                cnt++;
            }
        }

        if(cnt == 3) {
            cout << 1 << '\n';
        }else {
            cout << 0 << '\n';            
        }
    }

    return 0;
}