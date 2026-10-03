#include <bits/stdc++.h>
using namespace std;

int n, m, k; //크기, 참가자 수, 반복 횟수
int arr[11][11];
int temp_arr[11][11];
int person_dis;

struct Person {
    int r, c;
    bool isEscaped;
};

int ans_r, ans_c; // 출구 위치

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<Person> persons;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

// 가까워지는 방향으로 이동
bool isCloser(int r, int c, int nr, int nc) {
    int old_dis = abs(r-ans_r) + abs(c-ans_c);
    int new_dis = abs(nr-ans_r) + abs(nc-ans_c);

    if (new_dis < old_dis) {
        return true;
    }else {
        return false;
    }
}

int square_r, square_c, square_size;

bool findSquare() {
    for (int size = 1; size <= n; size++) {
        for (int r = 0; r+size <= n; r++) {
            for (int c = 0; c+size <= n; c++) {
                if (!(ans_r >= r && ans_r < r+size && ans_c >= c && ans_c < c+size)) continue;
                bool hasPerson = false;
                for (int p = 0; p < m; p++) {
                    if (persons[p].isEscaped) continue;
                    int pr = persons[p].r;
                    int pc = persons[p].c;

                    if (pr >= r && pr < r+size && pc >= c && pc < c+size) {
                        hasPerson = true;
                        break;
                    }
                }
                if (hasPerson) {
                    square_r = r;
                    square_c = c;
                    square_size = size;

                    return true;
                }
            }
        }
    }
    return false;
}

void rotateSquare() {

    for (int r = square_r; r < square_r + square_size; r++) {
        for (int c = square_c; c < square_c + square_size; c++) {

            int x = r - square_r;
            int y = c - square_c;

            int temp_r = y + square_r;
            int temp_c = square_size - x - 1 + square_c;

            temp_arr[temp_r][temp_c] = arr[r][c];
            if (temp_arr[temp_r][temp_c] > 0) {
                temp_arr[temp_r][temp_c]--;
            }
        }
    }

    for (int r = square_r; r < square_r + square_size; r++) {
        for (int c = square_c; c < square_c + square_size; c++) {
            arr[r][c] = temp_arr[r][c];
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (persons[i].isEscaped) continue;
        if (persons[i].r >= square_r && persons[i].r < square_r + square_size && 
            persons[i].c >= square_c && persons[i].c < square_c + square_size) {

            int x = persons[i].r - square_r;
            int y = persons[i].c - square_c;

            persons[i].r = y + square_r;
            persons[i].c = square_size - x - 1 + square_c;
        }
    }

    int x = ans_r - square_r;
    int y = ans_c - square_c;

    ans_r = y + square_r;
    ans_c = square_size - x - 1 + square_c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int temp_r;
        int temp_c;
        cin >> temp_r >> temp_c;
        temp_r--;
        temp_c--;
        persons.push_back({temp_r, temp_c, false});
    }

    cin >> ans_r >> ans_c;
    ans_r--;
    ans_c--;

    while (k--) {

        for (int i = 0; i < m; i++) {
            if (persons[i].isEscaped) continue;
            int r = persons[i].r;
            int c = persons[i].c;

            for(int j = 0; j < 4; j++) {
                int nr = r + dr[j];
                int nc = c + dc[j];

                if(inRange(nr, nc) && arr[nr][nc] == 0 ) {
                    // 가까워졌는지 체크
                    if (isCloser(r,c,nr,nc)) {
                        if (nr == ans_r && nc == ans_c) {
                            persons[i].isEscaped = true;
                        }
                        persons[i].r = nr;
                        persons[i].c = nc;
                        person_dis++;
                        break;
                    }
                }
            }
        }

        if (findSquare()) {
            rotateSquare();
        }
    }

    cout << person_dis << '\n';
    cout << ans_r+1 << " " << ans_c+1;

    return 0;
}