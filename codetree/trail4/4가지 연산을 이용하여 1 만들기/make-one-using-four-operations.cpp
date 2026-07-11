#include <iostream>
#include <queue>
using namespace std;

int N;
bool visited[1000004];
int arr[1000004];
int min_num[1000004];

void BFS(int n) {
    queue<int> Q;
    Q.push(n);
    visited[n] = true;

    if(n == 1) {
        cout << 0;
        return;
    }

    while(!Q.empty()) {
        int curr_num = Q.front();
        Q.pop();

        if(visited[curr_num+1] == false) {
            Q.push(curr_num+1);
            visited[curr_num+1] = true;
            min_num[curr_num+1] = min_num[curr_num] + 1;
        }

        if(visited[curr_num-1] == false) {
            Q.push(curr_num-1);
            visited[curr_num-1] = true;
            min_num[curr_num-1] = min_num[curr_num] + 1;        
        }

        if(curr_num % 2 == 0) {
            if(visited[curr_num/2] == false) {
                Q.push(curr_num/2);
                visited[curr_num/2] = true;
                min_num[curr_num/2] = min_num[curr_num] + 1;        
            }
        } 

        if(curr_num % 3== 0) {
            if(visited[curr_num/3] == false) {
                Q.push(curr_num/3);
                visited[curr_num/3] = true;
                min_num[curr_num/3] = min_num[curr_num] + 1;        
            }
        }

        if(min_num[1] != 0) {
            cout << min_num[1];
            return;
        }     
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    BFS(N);

    return 0;
}