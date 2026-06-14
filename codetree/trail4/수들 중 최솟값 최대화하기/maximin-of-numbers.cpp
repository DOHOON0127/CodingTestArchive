#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int grid[10][10];
bool visited[10][10];

vector<int> V;
vector<int> Max_V;

void findMin() {
    int min_num = INT_MAX;

    for(int i = 0; i < V.size(); i++) {
        if(min_num > V[i]) {
            min_num = V[i];
        }
    }

    Max_V.push_back(min_num);
}

void printV() {

    for(int i = 0; i < V.size(); i++) {
        cout << V[i] << ' ';
    }

    cout << '\n';
}

// 행과 열에 정확히 1개의 색칠된 칸만 오도록 하는 것
// 이번 row에서 하나의 칸을 색칠하는 함수
void choose(int row) {

    if(row == n) {
        findMin();
        // printV();
        return;
    }

    for(int i = 0; i < n; i++) {

        if(visited[row][i] == true) {
            continue;
        }

        V.push_back(grid[row][i]);

        // for(int r = 0; r < n; r++) {
        //     visited[row][r] = true;
        // }

        for(int c = 0; c < n; c++) {
            visited[c][i] = true;
        }

        choose(row+1);

        V.pop_back();

        for(int c = 0; c < n; c++) {
            visited[c][i] = false;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    choose(0);

    int max_num = INT_MIN;

    for(int i = 0; i < Max_V.size(); i++) {
        if(max_num < Max_V[i]) {
            max_num = Max_V[i];
        }
    }

    cout << max_num;

    return 0;
}
