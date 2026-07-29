#include <iostream>
using namespace std;

int n;
int r,c;
char arr[15][15];

int main() {
    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    char fisrt_color = arr[0][0];
    int cnt = 0;

    for(int i = 1; i < r-1; i++) {
        for(int j = 1; j < c-1; j++) {
            for(int p = i+1; p < r-1; p++) {
                for(int q = j+1; q < c-1; q++) {
                    
                    if(arr[i][j] != fisrt_color) {
                        if(arr[p][q] != arr[i][j]) {
                            cnt++;
                        }
                    }
                }
            }
        }
    } 

    if(arr[0][0] == arr[r-1][c-1]) {
        cout << 0;
    }
    else {
        cout << cnt;
    }


    return 0;
}