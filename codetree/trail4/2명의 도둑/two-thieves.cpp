// **1. 문제 분석 및 설계 (코드 작성 전)**

// - 입력의 최대 길이 등 상수 조건을 가장 먼저 확인
// - 이러한 상수 조건을 통해 요구되는 시간 복잡도를 유추
// - 어떤 자료 구조와 알고리즘을 쓸지 고민하고 머릿속에 전략을 세운 뒤에 코드 에디터로

// **2. 시뮬레이션 및 복잡도 분석 (제출 전)**

// - 일반적인 샘플 데이터와 엣지 케이스를 직접 생각해 내어 코드에 넣어보고 검증
// - 제출 전 마지막으로 자신이 짠 알고리즘의 시간 복잡도와 공간 복잡도(메모리)를 분석 이유를 스스로 설명

// **3. 정답 흡수 및 분석 (풀이 후)**

// - 정답을 맞혔더라도 다른 사람들의 다양한 풀이 방식과 더 깔끔한 코드를 찾기
// - 문제 접근부터 구현까지 30분~1시간(혹은 40분) 내로 끝내지 못했다면, 미련 없이 정답을 보고 다른 사람의 구현 노하우를 공부

// **4. 완벽한 내 것으로 만들기 위한 반복 학습**

// - 공부한 문제는 반드시 한 달 내로 다시 돌아와서 풀기
// - 다시 풀 때는 더 빠르고 깔끔하게 풀거나, 새로운 접근 방식으로 풀기
// - 해당 문제를 봤을 때 **15분 내로 풀어서 정답이 나올 때까지** 이 과정을 반복

#include <iostream>
#include <climits>
using namespace std;

int n,m,c;
int max_val = INT_MIN; // 가치의 최댓값
int arr[10][10];
int max_temp_val;

// 행에서 연속되는 m개의 칸 중에서 한도를 넘지 않으면서 최대의 가치를 가지도록 하는 함수
// idx: 현재 고를지 말지 결정할 M칸 내의 상대적 위치 (0 ~ m-1)
// weight: 지금까지 고른 물건들의 무게 합
// val: 지금까지 고른 물건들의 가치 합 (무게^2)
void findSubset(int r, int c_start, int idx, int weight, int val) {
    if (idx == m) {
        if (weight <= c) {
            max_temp_val = max(max_temp_val, val);
        }
        return;
    }

    int curr_weight = arr[r][c_start+idx];
    int curr_val = curr_weight * curr_weight;

    findSubset(r, c_start, idx+1, weight, val);

    if (weight + curr_weight <= c) {
        findSubset(r, c_start, idx+1, weight+curr_weight, val+curr_val);
    }

}

int findMax(int r, int c_start) {
    max_temp_val = 0;
    findSubset(r, c_start, 0, 0, 0);
    return max_temp_val;
}

bool isOverlap(int r1, int c1, int r2, int c2) {
    if (r1 != r2) {
        return false;
    }

    if (c1 + m - 1 < c2 || c2 + m -1 < c1) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> c;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // 도둑 1의 시작점
    for (int r1 = 0; r1 < n; r1++) {
        for (int c1 = 0; c1 < n-m+1; c1++) {

            for (int r2 = 0; r2 < n; r2++) {
                for (int c2 = 0; c2 < n-m+1; c2++) {

                    if (!isOverlap(r1, c1, r2, c2)) {
                        int current_val = findMax(r1, c1) + findMax(r2, c2);
                        max_val = max(max_val,current_val);
                    }
                }
            }

        }
    }

    cout << max_val;

    return 0;
}