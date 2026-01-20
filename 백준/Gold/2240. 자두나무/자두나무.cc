#include <bits/stdc++.h>
using namespace std;

int dp[1004][2][34];
int T, W;
int b[1004];

int go(int idx, int tree, int cnt)
{
    // 기저사례
    if (cnt < 0)
    {
        return -1e9;
    }

    if (idx == T)
    {
        return cnt == 0 ? 0 : -1e9;
    }

    // 메모이제이션
    int &ret = dp[idx][tree][cnt]; //dp[idx][tree][cnt]라는 긴 이름을 ret이라고 부름, 둘은 완전히 같은 메모리응 가리킴
    if (~ret) // if(ret != -1)과 똑같은 뜻 -> ~ 비트연산자는 0과 1을 반대로 뒤집는 연산자임
    // C++에서 0이 아닌 모든 수는 true, -1이라면 방문 안한거니까 방문하고 다른 값이라면 방문 한거니까 ret을 리턴함
    {
        return ret;
    }

    // 로직
    // ^는 XOR 연산자인데, 0은 1로, 1은 0으로 바꿔주는 스위치 역할
    return ret = max(go(idx+1, tree^1, cnt-1), go(idx+1, tree, cnt)) + (tree == b[idx]-1);
}

int main () {
    memset(dp, -1, sizeof(dp));
    cin >> T >> W;
    for (int i = 0; i < T; i++)
    {
        cin >> b[i];
    }
    cout << max(go(0, 1, W-1), go(0, 0, W)) << '\n';
    return 0;
}