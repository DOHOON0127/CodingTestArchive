#include <iostream>
using namespace std;

int n, m, r, c;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int curr_dir;

char arr[100][100];

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void simulation() {

    char curr_char = 'A';
    int count = 0;

    while(inRange(r, c) && arr[r][c] == '\0') {

        arr[r][c] = curr_char;

        int nr = r + dr[curr_dir];
        int nc = c + dc[curr_dir];

        if(!inRange(nr, nc) || arr[nr][nc] != '\0') {

            curr_dir = (curr_dir + 1) % 4;

            r += dr[curr_dir];
            c += dc[curr_dir];
        }
        else {
            r = nr;
            c = nc;
        }  

        count++;
        curr_char = 'A' + (count % 26); 

        // curr_char++;
    }
}




int main() {

    cin >> n >> m;



    simulation();



    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}