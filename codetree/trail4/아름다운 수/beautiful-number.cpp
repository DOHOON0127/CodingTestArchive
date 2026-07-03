#include <iostream>
#include <vector>

using namespace std;

// 아름다운 수 : a가 a번 "연속해서" 나온걸로만 이루어져 있는 수
// ex) 1333221, 111, 2222

int N;
vector<int> V;
int count;

// 아름다운 수인지를 판별하는 함수
bool isBeauty(int cnt) {
    int i = 0;

    for(i; i < cnt; ) {
        for(int j = 0; j < V[i]; j++) {
            if(V[i+j] != V[i]) {
                return false;
            }
        }
        i = i+V[i];
    }

    return true;
}

// 자리수에 맞게 1~4 중에 하나를 뽑아 수를 만드는 함수
void selectBeauty(int cnt) { // cnt : 자리수

    if(cnt == N+1) {
        if(isBeauty(cnt-1)) {
            count++;
        }
        return;
    }

    for(int i = 1; i <= 4; i++) {
        V.push_back(i);
        selectBeauty(cnt+1);
        V.pop_back();
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N; // N자리 아름다운 수의 개수를 출력
    
    selectBeauty(1);

    cout << count;

    return 0; 
}