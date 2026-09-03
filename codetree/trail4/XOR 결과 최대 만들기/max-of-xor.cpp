#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, m;

// N개의 음이 아닌 정수가 입력으로 주어졌을 때, 
// 그 중 M개의 정수를 뽑아 모두 XOR한 결과의 최댓값을 출력하는 코드를 작성

 

vector<int> V;
int arr[30];
int max_num = INT_MIN;

int clac() {

    int xor_sum = V[0];

    for(int i = 1; i < (int)V.size(); i++) {

        xor_sum = (xor_sum ^ V[i]);

    }


    return xor_sum;

}

void solve(int start, int cnt) {
    
    if(cnt == m) {
        int ans = clac();
        max_num = max(ans, max_num);
        return;
    }

    for(int i = start; i <= n; i++) {
        V.push_back(arr[i]);
        solve(i+1, cnt+1);
        V.pop_back();
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    solve(1, 0);

    cout << max_num;

    return 0;
}