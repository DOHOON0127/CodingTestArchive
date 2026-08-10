// 1. 상수조건, 시간복잡도, 자료구조, 알고리즘, 전략
// 2. 시간복잡도, 공간복잡도, 엣지 케이스
// 3. 다른 방법 뭐 있지?

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n,m,k; // 턴 수, 윷놀이 판 마지막 지점 번호, 말의 수
int max_score = INT_MIN;
int arr[12]; // 각 턴마다 나아갈 수 있는 거리가 저장
vector<int> V; // 몇번 말이 저장되어 있는지 

void choose(int cnt) {
    if(cnt == n) {

        int horse[4] = {1,1,1,1}; // 각 말이 갈 수 있는 거리의 수
        int temp_score = 0;

        // 턴수만큼 반복해서 
        for(int i = 0; i < n; i++) {

            int h = V[i];

            if(horse[h] < m) {
                horse[h] += arr[i];
                if(horse[h] >= m) {
                    temp_score++;
                }
            }
        }

        max_score = max(max_score, temp_score);
        
        return;
    }

    for(int i = 0; i < k; i++) {
        V.push_back(i); // i번 말을 고름
        choose(cnt+1);
        V.pop_back();
    }

}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    // n 턴만큼 진행해야 함
    for(int i = 0; i < n; i++) { 
        // 각 턴마다 나아갈 수 있는 거리가 주어짐
        cin >> arr[i];
        
    }

    choose(0);

    cout << max_score;

    return 0;
}