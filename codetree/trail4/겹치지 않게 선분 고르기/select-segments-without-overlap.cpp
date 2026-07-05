#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
int x1[15], x2[15];
vector<pair<int, int>> V;
vector<pair<int, int>> V_recur;
int ans;

bool isLineOverlap(pair<int, int> p1, pair<int, int> p2) {
    int ax1, ax2;
    tie(ax1, ax2) = p1;

    int bx1, bx2;
    tie(bx1, bx2) = p2;

    return ((ax1 <= bx1 && bx1 <= ax2)||(ax1 >= bx1 && ax1 <= bx2) || 
    (ax1 <= bx1 && bx2 <= ax2)|| (ax1 >= bx1 && bx2 >= ax2));
}

bool Possible() {
    for(int i = 0; i < (int)V_recur.size(); i++) {
        for(int j = i+1; j <(int)V_recur.size(); j++) {
            if(isLineOverlap(V_recur[i], V_recur[j])) {
                return false;
            }
        }
    }
    return true;
}

void selectLine(int cnt) {

    if(cnt == n) {
        if(Possible()) {
            ans = max(ans, (int)V_recur.size());
        }
        return;
    }

    V_recur.push_back(V[cnt]);
    selectLine(cnt+1);
    V_recur.pop_back();

    selectLine(cnt+1);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; // 선분의 개수

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> x2[i]; // 선분의 시작과 끝을 저장
        V.push_back({x1[i], x2[i]});
    }

    selectLine(0);

    cout << ans;

    return 0;
}
