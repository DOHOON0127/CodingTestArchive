#include <iostream>
#include <climits>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
int arr[20][20];
bool visited[20][20];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int max_gold;
int num_gold;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}

void BFS(int r1, int c1) {
    queue<pair<int, int >> Q;
    Q.push({r1, c1});
    visited[r1][c1] = true;

    int k = 0;
    int cnt_gold = 0;

    while(!Q.empty()) {
        int q_size = Q.size();

        for(int i = 0; i < q_size; i++) {
            int r,c;
            tie(r, c) = Q.front();
            Q.pop();

            if(arr[r][c] == 1 && visited[r][c] == true) {
                cnt_gold++;
            }

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(inRange(nr, nc) && visited[nr][nc] == false) {
                    Q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

        int cost = (k * k) + (k + 1) * (k + 1);

        if (cnt_gold * m >= cost) {
            max_gold = max(max_gold, cnt_gold);
        }
        
        k++;
    }    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if(arr[i][j] == 1) {
                num_gold++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            memset(visited, false, sizeof(visited));
            BFS(i, j);       
        }
    }

    cout << max_gold;


    return 0;
}