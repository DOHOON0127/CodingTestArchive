#include <iostream>

using namespace std;

int n, m;
int arr[100][100];
bool visited[100][100];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int curr_dir;
int r, c;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void simulate() {

    int num_cnt = 1;

    while(inRange(r,c) && visited[r][c] == false) {

        arr[r][c] = num_cnt;
        visited[r][c] = true;

        r += dr[curr_dir];
        c += dc[curr_dir];

        if(!inRange(r, c) || visited[r][c] == true) {

            r -= dr[curr_dir];
            c -= dc[curr_dir];
            
            curr_dir = (curr_dir + 1) % 4;

            r += dr[curr_dir];
            c += dc[curr_dir];
        }

        num_cnt++;

    }


}

int main() {
    cin >> n >> m;





    simulate();



    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
