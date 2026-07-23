#include <iostream>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int n, nr, nc;

void move(char dir, int distance) {
    
    if(dir == 'W') {
        nr = nr + dr[3]*distance;
        nc = nc + dc[3]*distance;
    }
    else if(dir == 'S'){
        nr = nr + dr[2]*distance;
        nc = nc + dc[2]*distance;
    }else if(dir == 'N'){
        nr = nr + dr[0]*distance;
        nc = nc + dc[0]*distance;

    }else if(dir == 'E') {
        nr = nr + dr[1]*distance;
        nc = nc + dc[1]*distance;
    }
}

int main() {
    cin >> n;

    char dir;
    int distance;

    for(int i = 0; i < n; i++) {

        cin >> dir >> distance;
        move(dir, distance);

    }

    cout << nc << " " << -nr;

    return 0;
}