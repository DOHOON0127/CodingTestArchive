#include <iostream>
#include <vector>
using namespace std;

// 1이상 K이하의 숫자를 하나 고르는 행위를
// N번 반복하여 나올 수 있는 모든 순서쌍?
// 단, 연속하여 같은 숫자 3번 나오는 경우는 제외
int K, N;
vector<int> V;

void printVector() {
    for(int i = 0; i < V.size(); i++) {
        cout << V[i] << " ";
    }
    cout << '\n';
}


// idx번째 자리의 수를 정하는 함수
void solve(int idx, int K, int N) {

    if(idx >= 4) {
        if((V[idx-4] == V[idx-3]) && (V[idx-3] == V[idx-2])) {
            return;
        }
    }

    if(idx == N+1) {
        printVector();
        return;
    }

    for(int i = 1; i <= K; i++) {
        V.push_back(i);
        solve(idx+1, K, N);
        V.pop_back();
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;

    solve(1, K, N);

    return 0;
}