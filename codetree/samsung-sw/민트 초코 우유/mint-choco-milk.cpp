#include <bits/stdc++.h>
using namespace std;

int N, T;

struct Student {
    string food;
    int B; // 신앙심
    int r, c; // 좌표
};

Student students[50][50];

int dr[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dc[4] = {0, 0, -1, 1};

bool visited[50][50];

bool inRange(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N);
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    int ar = a.first;
    int ac = a.second;
    int br = b.first;
    int bc = b.second;

    if (students[ar][ac].food.size() != students[br][bc].food.size()) {
        return students[ar][ac].food.size() < students[br][bc].food.size();
    }

    if (students[ar][ac].B != students[br][bc].B) {
        return students[ar][ac].B > students[br][bc].B;
    }

    if (ar != br) {
        return ar < br;
    }

    return ac < bc;
}

string mergeFood(string a, string b) {
    bool hasT = false;
    bool hasC = false;
    bool hasM = false;

    for (char ch : a) {
        if (ch == 'T') hasT = true;
        if (ch == 'C') hasC = true;
        if (ch == 'M') hasM = true;
    }
    for (char ch : b) {
        if (ch == 'T') hasT = true;
        if (ch == 'C') hasC = true;
        if (ch == 'M') hasM = true;
    }
    string result = "";

    if (hasT) result += 'T';
    if (hasC) result += 'C';
    if (hasM) result += 'M';

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            students[i][j].food = s.substr(j,1);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> students[i][j].B;
            students[i][j].r = i;
            students[i][j].c = j;
        }
    }

    while (T--) {
        // 아침 -> 모든학생 신항심 +1
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                students[i][j].B += 1;
            }
        }

        // 점심
        // 그룹 선정
        vector<pair<int, int>> kings;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == true) continue;
                vector<pair<int, int>> group;
                queue<pair<int, int>> Q;

                string food = students[i][j].food;

                Q.push({i,j});
                visited[i][j] = true;

                while (!Q.empty()) {
                    int r = Q.front().first;
                    int c = Q.front().second;
                    Q.pop();

                    group.push_back({r,c});

                    for (int dir = 0; dir < 4; dir++) {
                        int nr = r + dr[dir];
                        int nc = c + dc[dir];

                        if (inRange(nr,nc) && visited[nr][nc] == false
                            && students[nr][nc].food == food) {

                            visited[nr][nc] = true;
                            Q.push({nr, nc});
                         }
                    }
                }
                // 그룹 내 대표자 선정 (신앙심 가장 높고, r제일 작고, c제일 작음)
                int king_r = group[0].first;
                int king_c = group[0].second;

                for (int g = 1; g < group.size(); g++) {
                    int r = group[g].first;
                    int c = group[g].second;

                    if (students[r][c].B > students[king_r][king_c].B) {
                        king_r = r;
                        king_c = c;
                    }
                    else if (students[r][c].B == students[king_r][king_c].B) {
                        if (r < king_r || (r == king_r && c < king_c)) {
                            king_r = r;
                            king_c = c;
                        }
                    }
                }
                // 선정 끝나면 대표자 신앙심 "(그룹안에 있는 사람수-1)"만큼 증가, 대표자 제외한 나머지 사람은 신앙심 -1씩
                for (int g = 0; g < group.size(); g++) {
                    int r = group[g].first;
                    int c = group[g].second;

                    if (r == king_r && c == king_c) continue;

                    students[r][c].B--;
                }
                students[king_r][king_c].B += group.size()-1;
                kings.push_back({king_r, king_c});
            }
        }

        // 저녁
        bool defended[50][50];
        memset(defended, false, sizeof(defended));

        sort(kings.begin(), kings.end(), cmp);

        for (int i = 0; i < kings.size(); i++) {
            int r = kings[i].first;
            int c = kings[i].second;

            if (defended[r][c]) continue;

            int B = students[r][c].B;

            int dir = B % 4;
            int x = B-1;

            string spreadFood = students[r][c].food;

            students[r][c].B = 1;

            int nr = r;
            int nc = c;

            while (x > 0) {
                nr += dr[dir];
                nc += dc[dir];

                if (!inRange(nr,nc)) break;

                if (students[nr][nc].food == spreadFood) {
                    continue;
                }
                defended[nr][nc] = true;

                int y = students[nr][nc].B;

                if (x > y) {
                    students[nr][nc].food = spreadFood;
                    students[nr][nc].B++;
                    x -= (y+1);
                }
                else {
                    students[nr][nc].food = mergeFood(students[nr][nc].food, spreadFood);
                    students[nr][nc].B += x;
                    x = 0;
                }
            }
        }

        long long TCM = 0;
        long long TC = 0;
        long long TM = 0;
        long long CM = 0;
        long long M = 0;
        long long C = 0;
        long long T = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                string food = students[i][j].food;
                long long B = students[i][j].B;

                if (food == "TCM") TCM += B;
                else if (food == "TC") TC += B;
                else if (food == "TM") TM += B;
                else if (food == "CM") CM += B;
                else if (food == "M") M += B;
                else if (food == "C") C += B;
                else if (food == "T") T += B;
            }
        }

        cout << TCM << " "
             << TC << " "
             << TM << " "
             << CM << " "
             << M << " "
             << C << " "
             << T << '\n';
    }

    return 0;
}