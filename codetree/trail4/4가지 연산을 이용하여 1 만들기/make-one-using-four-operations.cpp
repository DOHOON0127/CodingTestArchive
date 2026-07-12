#include <iostream>
#include <queue>
using namespace std;

const int MAX_LIMIT = 1000000;

int N;
bool visited[MAX_LIMIT+4];
int arr[MAX_LIMIT+4];
int min_num[MAX_LIMIT+4];

queue<int> Q;

void push_node(int next_num, int curr_num) {
    if(next_num >=1 && next_num <= MAX_LIMIT && visited[next_num] == false) {
        Q.push(next_num);
        visited[next_num] = true;
        min_num[next_num] = curr_num + 1;
    }
}

void BFS(int n) {
    Q.push(n);
    visited[n] = true;

    while(!Q.empty()) {
        int curr_num = Q.front();
        Q.pop();


        if(curr_num == 1) {
            cout <<  min_num[1];
            return;
        }


        push_node(curr_num+1, min_num[curr_num]);
        push_node(curr_num-1, min_num[curr_num]);

        if(curr_num % 2 == 0) {
            push_node(curr_num / 2, min_num[curr_num]);
        } 

        if(curr_num % 3== 0) {
            push_node(curr_num / 3, min_num[curr_num]);
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