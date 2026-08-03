#include <iostream>

#define MAX_DIR 8
using namespace std;


int n, m;
char arr[50][50];

int dr[MAX_DIR] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[MAX_DIR] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 'L') {

                while(true) {
                    for(int k = 0; k <MAX_DIR; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if(arr[nr][nc] == 'E') {
                            int nr1 = nr + dr[k];
                            int nc1 = nc + dc[k];

                            if(arr[nr1][nc1] == 'E') {
                                cnt++;
                            }
                        }  
                    }
                    break;

                }


            }
        }
    }

    cout << cnt;
    


    return 0;
}