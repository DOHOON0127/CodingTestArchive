#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[20][20];
int dr[4] = {-1, -1, 1, 1};
int dc[4] = {1, -1, -1, 1};
int max_sum = INT_MIN;

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < n);
}
// k 4 l 2 -> 4 2 4 2
int getSum(int i, int j, int k, int l) {

    int sum = 0;
    int r = i;
    int c = j;

    int dir = 0;
    
    for(int a = 0; a < k; a++) {
        sum += arr[r][c];
            
        r = r + dr[dir];
        c = c + dc[dir];

        if(!inRange(r,c)) return 0;
    }

    dir++;

    for(int a = 0; a < l; a++) {
        sum += arr[r][c];
            
        r = r + dr[dir];
        c = c + dc[dir];

        if(!inRange(r,c)) return 0;
    }  
    

    dir++;

    for(int a = 0; a < k; a++) {
        sum += arr[r][c];
            
        r = r + dr[dir];
        c = c + dc[dir];

        if(!inRange(r,c)) return 0;
    }  


    dir++;

    for(int a = 0; a < l; a++) {
        sum += arr[r][c];
            
        r = r + dr[dir];
        c = c + dc[dir];

        if(!inRange(r,c)) return 0;
    }  

    return sum;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {           
           for(int k = 1; k < n; k++) {
                for(int l = 1; l < n; l++) {
                    max_sum = max(max_sum, getSum(i,j,k,l));
                }
           }
        }
    } 

    cout << max_sum;

    return 0;
}