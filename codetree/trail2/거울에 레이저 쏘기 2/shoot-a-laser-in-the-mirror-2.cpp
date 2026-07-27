#include <iostream>

using namespace std;

int n;
char arr[1000][1000];
int k;

int move_dir;
int r, c;

void initialize(int num) {
    if(num <= n) {
        r = 0; 
        c = num - 1;
        move_dir = 0;
    }
    else if(num <= n * 2) {
        r = num - n - 1;
        c = n - 1;
        move_dir = 1;
    }
    else if(num <= n * 3) {
        r = n - 1;
        c = n - (num - 2 * n);
        move_dir = 2;
    }
    else {
        r = n - (num - 3 * n);
        c = 0;
        move_dir = 3;
    }
}

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void Move(int dir) {
    int dr[4] = {1, 0, -1 ,0};
    int dc[4] = {0, -1, 0, 1};

    r += dr[dir];
    c += dc[dir];

    move_dir = dir; 
}

int simulate() {
    int move_num = 0;
    while(inRange(r, c)) {
        if(arr[r][c] == '/') {
            Move(move_dir ^ 1);
        }
        else {
            Move(3 - move_dir);
        }

        move_num += 1;
    }

    return move_num;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> k;

    initialize(k);

    int move_num = simulate();

    cout << move_num;

    return 0;
}