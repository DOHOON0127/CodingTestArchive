#include <iostream>
#include <list>
#include <tuple>
#include <cmath>
#include <climits>
#include <iterator>
using namespace std;

int n;
int min_len = INT_MAX;

void distance(const list<pair<int, int>>& l) {
    auto it = l.begin();
    it++;

    int sum_dis = 0;

    for(it; it != l.end(); it++) {
        pair<int, int> temp = *it;

        int x1, y1;
        tie(x1, y1) = temp;

        pair<int, int> temp1 = *prev(it);


        int x2, y2;
        tie(x2, y2) = temp1;

        sum_dis += (abs(x2-x1) + abs(y2-y1));

    }

    min_len = min(min_len, sum_dis);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    list<pair<int, int>> L;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        L.push_back({x, y});
    }

    list<pair<int, int>>::iterator it = L.begin();
    // auto it = L.begin();
    it++;

    for(int i = 1; i < n-1; i++) {

        pair<int, int> backup = *it;
        
        it = L.erase(it);

        // 이제 맨해튼 거리를 구하고 최소값 갱신하고
        distance(L);

        L.insert(it, backup);

    }

    cout << min_len;

    return 0;
}