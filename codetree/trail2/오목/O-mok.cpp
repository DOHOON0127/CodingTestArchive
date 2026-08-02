#include <iostream>
#include <tuple>
#include <queue>
#include <climits>

#define DIR_NUM 8

using namespace std;

int arr[19][19];


// int max_black = INT_MIN;
// int max_white = INT_MIN;

bool visited[19][19];

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool inRange(int r, int c) {
    return (r >=0 && r < 19 && c >= 0 && c < 19);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) 
            cin >> arr[i][j];
    // 알 없음 : 0
    // 검 : 1, 흰 : 2

    for(int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {

            if(arr[i][j] == 0) continue;

            for(int k = 0; k < DIR_NUM; k++) {
                int cnt = 1;
                int cur_r = i;
                int cur_c = j;

                while(true) {
                    int nr = cur_r + dr[k];
                    int nc = cur_c + dc[k]; 

                    if(!inRange(nr, nc)) {
                        break;
                    }         

                    if(arr[nr][nc] != arr[i][j]) {
                        break;
                    }        
                    
                    cnt++;
                    cur_r = nr;
                    cur_c = nc;

                }

                if(cnt == 5) {
                    cout << arr[i][j] << '\n';
                    cout << i + 2 * dr[k] + 1 << " " << j + 2 * dc[k] + 1;
                    return 0;
                }
            }
            
        }
    }

    cout << 0;


    


    return 0;
}