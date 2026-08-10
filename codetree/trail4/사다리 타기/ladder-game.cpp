#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, m; // 세로줄 수, 가로줄 수
vector<pair<int, int>> lines; // 높이, 세로줄 저장
vector<pair<int, int>> selected_lines;
int target_result[15]; // 사다리 결과 저장 3 4 1 2
int ans = INT_MAX;

void simulate(int current_result[], const vector<pair<int, int>>& current_lines) {
    for(int i = 1; i <= n; i++) {
        current_result[i] = i;
    }

    // for (int i = 0; i < current_lines.size(); i++) 
    // pair<int, int> line = current_lines[i];
    // int pos = line.second;
    // // ...


    for(auto line : current_lines) {
        int pos = line.second;
        swap(current_result[pos], current_result[pos+1]);
    }
}

void choose(int idx, int cnt) {
    if(idx == m) {
        int current_result[15];
        simulate(current_result, selected_lines);

        bool is_same = true;
        for(int i = 1; i <= n; i++) {
            if(target_result[i] != current_result[i]) {
                is_same = false;
                break;
            }
        }

        if(is_same) {
            ans = min(ans, cnt);
        }
        return;
    }

    // 현재 가로줄 포함x -> 넘어감
    choose(idx+1, cnt);

    // 현재 가로줄 포함o -> 넘어감
    selected_lines.push_back(lines[idx]);
    choose(idx+1, cnt+1);
    selected_lines.pop_back();

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        lines.push_back({b,a});
    }

    sort(lines.begin(), lines.end());

    simulate(target_result, lines);

    choose(0,0);

    cout << ans;

    return 0;
}
