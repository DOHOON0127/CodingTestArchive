#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 100000;
int n, m;
int x[MAX_N], y[MAX_N];

struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        long long distA = abs(a.first) + abs(a.second);
        long long distB = abs(b.first) + abs(b.second);

        if(distA != distB) {
            return distA > distB;
        }

        if(a.first != b.first) {
            return a.first > b.first;
        }

        return a.second > b.second;

    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        pq.push(make_pair(x[i], y[i]));
    }

    // 원점에서 가장 가깝다
    // 각각 제곱의 합이 제일 작다
    // 3,3 4,1

    for(int i = 0; i < m; i++) {
        pair<int, int> temp = pq.top();
        pq.pop();
        temp.first += 2;
        temp.second += 2;
        pq.push(temp);
    }


    cout << pq.top().first << ' ' << pq.top().second << '\n';


    return 0;
}
