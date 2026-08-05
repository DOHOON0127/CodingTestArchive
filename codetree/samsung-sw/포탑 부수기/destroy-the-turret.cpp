#include <iostream>
#include <climits>
#include <cstring>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;

// 레이저 이동 방향 (우, 하, 좌, 상) - 우선순위 순서
int dr[4] = {0, 1, 0, -1}; 
int dc[4] = {1, 0, -1, 0};

// 포탄 폭발 8방향 (좌상, 상, 우상, 좌, 우, 좌하, 하, 우하)
int br[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int bc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int wr, wc; // 공격자 좌표
int sr, sc; // 타겟 좌표

class Potab {
public:
    int r; 
    int c; 
    int time; // 마지막으로 공격한 턴 번호
    int power; // 공격력

    Potab(int r, int c, int time, int power) {
        this->r = r;
        this->c = c;
        this->time = time;
        this->power = power;
    }
    Potab() {};
};

Potab potabs[10][10];
bool visited[10][10];
bool is_attacked[10][10]; // 해당 턴에 공격에 관여했는지 여부
pair<int, int> back_pos[10][10];

// 공격자 선정 비교 함수 (가장 약한 포탑)
bool cmp_attacker(const Potab& a, const Potab& b) {
    if (a.power != b.power) return a.power < b.power;
    if (a.time != b.time) return a.time > b.time;
    if ((a.r + a.c) != (b.r + b.c)) return (a.r + a.c) > (b.r + b.c);
    return a.c > b.c;
}

// 타겟 선정 비교 함수 (가장 강한 포탑)
bool cmp_attack(const Potab& a, const Potab& b) {
    if (a.power != b.power) return a.power > b.power;
    if (a.time != b.time) return a.time < b.time;
    if ((a.r + a.c) != (b.r + b.c)) return (a.r + a.c) < (b.r + b.c);
    return a.c < b.c;
}

void selectAttacker(int turn) {
    vector<Potab> active_potabs;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (potabs[r][c].power > 0) {
                active_potabs.push_back(potabs[r][c]);
            }
        }
    }

    sort(active_potabs.begin(), active_potabs.end(), cmp_attacker);
    Potab attacker = active_potabs.front();
    
    wr = attacker.r;
    wc = attacker.c;
    
    // 핸디캡 적용 및 공격 시간 갱신
    potabs[wr][wc].power += (N + M);
    potabs[wr][wc].time = turn; 
    is_attacked[wr][wc] = true; // 공격 관여 O
}

void selectStrongPotab() {
    vector<Potab> active_potabs;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (r == wr && c == wc) continue; // 공격자는 타겟 제외
            if (potabs[r][c].power > 0) {
                active_potabs.push_back(potabs[r][c]);
            }
        }
    }

    sort(active_potabs.begin(), active_potabs.end(), cmp_attack);
    Potab target = active_potabs.front();
    
    sr = target.r;
    sc = target.c;
}

bool lazerAttack() {
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            back_pos[i][j] = {-1, -1};
        }
    }

    queue<pair<int, int>> Q;
    Q.push({wr, wc});
    visited[wr][wc] = true;
    bool can_lazer = false; 

    while (!Q.empty()) {
        int r, c;
        tie(r, c) = Q.front();
        Q.pop();

        if (r == sr && c == sc) {
            can_lazer = true;
            break;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nr = (r + dr[dir] + N) % N;
            int nc = (c + dc[dir] + M) % M;

            if (visited[nr][nc] == false && potabs[nr][nc].power > 0) {
                Q.push({nr, nc});
                visited[nr][nc] = true;
                back_pos[nr][nc] = {r, c};
            }
        }
    }

    if (!can_lazer) return false;

    // 경로 역추적 및 데미지 적용
    int curr_r = sr;
    int curr_c = sc;
    int attack_power = potabs[wr][wc].power; 

    while (!(curr_r == wr && curr_c == wc)) {
        if (curr_r == sr && curr_c == sc) {
            potabs[curr_r][curr_c].power -= attack_power;
        } else {
            potabs[curr_r][curr_c].power -= (attack_power / 2);
        }
        
        is_attacked[curr_r][curr_c] = true; // 공격 관여 O

        pair<int, int> prev = back_pos[curr_r][curr_c];
        curr_r = prev.first;
        curr_c = prev.second;
    }
    
    return true; 
}

// ⭐️ 새로 추가된 포탄 공격 로직
void bombAttack() {
    int attack_power = potabs[wr][wc].power;
    
    // 1. 타겟에게 100% 데미지
    potabs[sr][sc].power -= attack_power;
    is_attacked[sr][sc] = true;

    // 2. 주변 8방향 50% 데미지
    for (int i = 0; i < 8; i++) {
        int nr = (sr + br[i] + N) % N;
        int nc = (sc + bc[i] + M) % M;

        // 공격자 본인은 포탄 피해를 받지 않음
        if (nr == wr && nc == wc) continue;

        // 살아있는 포탑만 데미지 입히고 공격 관여 처리
        if (potabs[nr][nc].power > 0) {
            potabs[nr][nc].power -= (attack_power / 2);
            is_attacked[nr][nc] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int power;
            cin >> power;
            potabs[i][j] = Potab(i, j, 0, power);
        }
    }

    // K번의 턴 진행
    for (int turn = 1; turn <= K; turn++) {
        
        // 1. 살아있는 포탑 개수 세기 (1개 이하면 즉시 종료)
        int alive_cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (potabs[i][j].power > 0) alive_cnt++;
            }
        }
        if (alive_cnt <= 1) break;

        // 턴 시작 시 공격 관여 여부 초기화
        memset(is_attacked, false, sizeof(is_attacked));

        // 2. 공격자 선정 (현재 턴 번호를 넘김)
        selectAttacker(turn);

        // 3. 타겟 선정
        selectStrongPotab();

        // 4. 레이저 공격 시도, 안 되면 포탄 공격
        if (!lazerAttack()) {
            bombAttack();
        }

        // 5. 포탑 정비 (공격 무관한 살아있는 포탑 +1)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (potabs[i][j].power > 0 && is_attacked[i][j] == false) {
                    potabs[i][j].power += 1;
                }
            }
        }
    }

    // 모든 턴 종료 후 가장 강한 포탑 출력
    int max_power = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (potabs[i][j].power > 0) {
                max_power = max(max_power, potabs[i][j].power);
            }
        }
    }
    
    cout << max_power << "\n";

    return 0;
}