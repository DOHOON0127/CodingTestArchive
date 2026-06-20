#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int N;
int arr[30][30];
int visited[30][30];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<int> V;
int cnt = 1;

void DFS(int curr_r, int curr_c) {

    for(int i = 0; i < 4; i++) {
        int nr = curr_r + dr[i];
        int nc = curr_c + dc[i];

        if(nr >= 0 && nr < N && nc >= 0 && nc < N && visited[nr][nc] == false && arr[nr][nc] == 1) {
            visited[nr][nc] = true;
            cnt++;
            DFS(nr, nc);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 1 && visited[i][j] == false) {
                visited[i][j] = true;
                DFS(i, j);
                V.push_back(cnt);
                cnt = 1;
            }
        }
    }

    cout << V.size() << '\n';

    sort(V.begin(), V.end());

    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << '\n';
    }


    return 0;
}