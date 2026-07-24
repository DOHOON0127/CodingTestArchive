#include <iostream>

using namespace std;

string comment;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dir = 0;
int cnt_time = 0;
int x, y, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> comment;

    for(int i = 0; i < (int)comment.length(); i++) {
        if(comment[i] == 'L') {
            dir = (dir - 1 + 4) % 4;
            cnt_time++;
        }
        else if(comment[i] == 'R') {
            dir = (dir + 1) % 4;
            cnt_time++;
        }
        else {
            x += dx[dir];
            y += dy[dir];
            cnt_time++;

            if(x == 0 && y ==0) {
                ans = cnt_time;
                break;
            }
        }
    }

    if(ans != 0) {
        cout << ans;
    }
    else {
        cout << -1;
    }


    return 0;
}