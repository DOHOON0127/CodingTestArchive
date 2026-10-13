#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int s[100000];
int e[100000];

vector<pair<int, int>> V;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    
    if(a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
        V.push_back({s[i], e[i]});
    }

    // 0 1
    // 2 3
    // 1 9
    // 8 23

    sort(V.begin(), V.end(), cmp);

    int cnt = 1;
    int a = V[0].second;
    int b = V[1].first;


    for(int i = 1; i < n; i++) {
        if(a <= b) {
            cnt++;
            if(i == n-1) break;
            a = V[i].second;
            b = V[i+1].first;
        }else {
            b = V[i+1].first;
        }
    }

    cout << cnt;



    

    return 0;
}
