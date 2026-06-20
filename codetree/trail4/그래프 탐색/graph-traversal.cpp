#include <iostream>
using namespace std;

int N,M;
bool visited[1004];
int arr[1004][1004];
int x,y; // 임시 값
int count;

void DFS(int curr) {

    for(int i = 1; i <= N; i++) {
        if(!visited[i] && arr[curr][i] == 1) {
            // cout << i << '\n';
            count++;
            visited[i] = true;
            DFS(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M; // 정점, 간선

    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    visited[1] = true;
    DFS(1);

    cout << count;

    return 0;
}

