#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

int N;
int arr[20][20];
int curr_bomb;
int temp_curr_bomb;
int max_bomb = INT_MIN;
vector<int> V;
vector<pair<int, int>> V_bomb;

void countBombNum() {
    temp_curr_bomb = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 1){
                temp_curr_bomb++;
            }
        }
    }

    if(max_bomb < temp_curr_bomb) {
        max_bomb = temp_curr_bomb;
    }
}

// ex) 폭탄이 5개있다고 가정하면 각 폭탄은 3가지 종류임 이걸 다 계산 때리면 되는 것
void selectBomb(int cnt) { // cnt : 폭탄의 개수

    if(cnt == curr_bomb+1) {
        memset(arr, 0, sizeof(arr));
        for(int k = 0; k < curr_bomb; k++) {
            arr[V_bomb[k].first][V_bomb[k].second] = 1;
        }

        for(int i = 0; i < curr_bomb; i++) {
            if(V[i] == 1) {
                if(V_bomb[i].first-2 >= 0 && V_bomb[i].first-2 < N) {
                    arr[V_bomb[i].first-2][V_bomb[i].second] = 1;
                } 
                if(V_bomb[i].first-1 >= 0 && V_bomb[i].first-1 < N) {
                    arr[V_bomb[i].first-1][V_bomb[i].second] = 1;
                } 
                if(V_bomb[i].first+1 >= 0 && V_bomb[i].first+1 < N) {
                    arr[V_bomb[i].first+1][V_bomb[i].second] = 1;
                } 
                if(V_bomb[i].first+2 >= 0 && V_bomb[i].first+2 < N) {
                    arr[V_bomb[i].first+2][V_bomb[i].second] = 1;
                } 
            }
            else if(V[i] == 2) {
                if(V_bomb[i].first-1 >= 0 && V_bomb[i].first-1 < N) {
                    arr[V_bomb[i].first-1][V_bomb[i].second] = 1;
                } 
                if(V_bomb[i].second+1 >= 0 && V_bomb[i].second+1 < N) {
                    arr[V_bomb[i].first][V_bomb[i].second+1] = 1;
                } 
                if(V_bomb[i].first+1 >= 0 && V_bomb[i].first+1 < N) {
                    arr[V_bomb[i].first+1][V_bomb[i].second] = 1;
                } 
                if(V_bomb[i].second-1 >= 0 && V_bomb[i].second-1 < N) {
                    arr[V_bomb[i].first][V_bomb[i].second-1] = 1;
                } 
            }
            else {
                if(V_bomb[i].first-1 >= 0 && V_bomb[i].first-1 < N
                && V_bomb[i].second-1 >= 0 && V_bomb[i].second-1 < N) 
                {
                    arr[V_bomb[i].first-1][V_bomb[i].second-1] = 1;
                } 
                if(V_bomb[i].first-1 >= 0 && V_bomb[i].first-1 < N
                && V_bomb[i].second+1 >= 0 && V_bomb[i].second+1 < N) 
                {
                    arr[V_bomb[i].first-1][V_bomb[i].second+1] = 1;
                } 
                if(V_bomb[i].first+1 >= 0 && V_bomb[i].first+1 < N
                && V_bomb[i].second+1 >= 0 && V_bomb[i].second+1 < N) 
                {
                    arr[V_bomb[i].first+1][V_bomb[i].second+1] = 1;
                } 
                if(V_bomb[i].first+1 >= 0 && V_bomb[i].first+1 < N
                && V_bomb[i].second-1 >= 0 && V_bomb[i].second-1 < N) 
                {
                    arr[V_bomb[i].first+1][V_bomb[i].second-1] = 1;
                } 
            }
        }

        countBombNum();
        // cout << max_bomb << '\n';

        return;
    }

    for(int i = 1; i <= 3; i++) {
        V.push_back(i);
        selectBomb(cnt+1);
        V.pop_back();
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                curr_bomb++;
                V_bomb.push_back({i, j});
            }
        }
    }

    selectBomb(1);

    cout << max_bomb;

    return 0;
}