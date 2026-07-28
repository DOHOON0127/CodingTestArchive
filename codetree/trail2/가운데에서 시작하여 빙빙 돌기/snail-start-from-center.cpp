#include <iostream>

using namespace std;

int n;
int arr[100][100];
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

int curr_dir;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int r = n / 2;
    int c = n / 2;

    int cnt = 1;
    int num = 1;

    while(true) {

        for(int i = 0; i < cnt; i++) {
            arr[r][c] = num;

            int nr = r + dr[curr_dir];
            int nc = c + dc[curr_dir];

            r = nr;
            c = nc;

            num++;

            if(i == cnt - 1) {
                curr_dir = (curr_dir + 1) % 4;
            }
        }

        if(curr_dir == 0 || curr_dir == 2) {
            cnt++;
        } 

        if(!inRange(r, c)) {
            break;
        }

    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
