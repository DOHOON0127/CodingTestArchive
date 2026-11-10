#include <vector>
#include <bits/stdc++.h>
using namespace std;

int n,m;
bool visited[100][100];
int dist[100][100];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool inRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

int solution(vector<vector<int> > maps) {
    int answer = 0;
    
    n = maps.size(); // 열 r 
    m = maps[0].size(); // 행 c
    
    queue<pair<int, int> > Q;
    Q.push({0,0});
    visited[0][0] = true;
    
    while(!Q.empty()){
        auto [r, c] = Q.front();
        Q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            
            if(!inRange(nr, nc)) continue;
            if(visited[nr][nc]) continue;
            if(maps[nr][nc] == 0) continue;
            
            Q.push({nr, nc});
            visited[nr][nc] = true;
            dist[nr][nc] = dist[r][c] + 1;
        }
    }    
    
    
    if(dist[n-1][m-1] == 0) {
        answer = -1;
    }else {
        answer = dist[n-1][m-1] + 1;
    }
    
    return answer;
}