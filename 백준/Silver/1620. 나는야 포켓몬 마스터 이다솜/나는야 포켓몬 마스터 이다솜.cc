#include <bits/stdc++.h>
using namespace std;

int N; // 포켓몬 개수
int M; // 문제의 개수

// 둘다 십만 이하
string s[100004];

map<string, int> mp; // 이름으로 번호 찾기용 ("Pikachu" -> 1)

string input;

int tmp;

int main () {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> input;

        s[i] = input;

        mp.insert({input, i});

    }

    for (int i = 1; i <= M; i++) {
        cin >> input;

        if(atoi(input.c_str()) != 0) {
            cout << s[atoi(input.c_str())] << '\n';
        }else {
            cout << mp[input] << '\n';
        }

    }
    return 0;
}