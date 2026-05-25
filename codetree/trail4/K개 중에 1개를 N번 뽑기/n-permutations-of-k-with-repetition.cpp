#include <iostream>
#include <vector>
using namespace std;

vector<int> V;

void printVector() {
    for(int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
    cout << '\n';
}

// depth번째 자리에 넣을 숫자를 결정하는 함수
void choose(int depth, int K, int N) { // 1이상 K이하의 숫자를 고르는 행위를 N번 반복한다.

    // 종료조건 : depth == N+1이면 모든 자리를 다 채운것
    if(depth == N+1) {
        printVector();
        return;
    }

    // 현재 선택지는 1부터 K까지 중에 하나
    for(int i = 1; i <= K; i++) {
        V.push_back(i);
        choose(depth+1, K, N);
        V.pop_back();
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, N;

    cin >> K >> N; // 1이상 K이하의 숫자를 고르는 행위를 N번 반복한다.

    choose(1, K, N);

    return 0;
}