#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> V;

void printVector() {
    for(int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
    cout << '\n';
}

// start: 이번에 고를 수 있는 최소 숫자, cnt: 지금까지 고른 개수
void choose(int start, int cnt) {

    if(cnt == M) {
        printVector();
        return;
    }

    for(int i = start; i <= N; i++) {
        V.push_back(i);
        choose(i + 1, cnt + 1);
        V.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1이상 N이하의 숫자 중 M개를 골라 만들 수 있는 모든 조합
    cin >> N >> M;

    choose(1, 0);
    
    return 0;
}