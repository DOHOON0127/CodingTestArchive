#include <iostream>

using namespace std;

string command;

int dir_num = 3;
int x, y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int nx, ny;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> command;

    for(int i = 0; i < (int)command.length(); i++) {
        if(command[i] == 'L') {
            dir_num = (dir_num - 1 + 4) % 4;
        }
        else if(command[i] == 'R') {
            dir_num = (dir_num + 1) % 4;
        }
        else {
            nx = x + dx[dir_num];
            ny = y + dy[dir_num];
            x = nx;
            y = ny;
        }
    }

    cout << nx << " " << ny;

    return 0;
}