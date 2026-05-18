#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    int temp;
    priority_queue<int> pq;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        pq.push(-temp);

        if (i < 2) {
            cout << -1 << '\n';
            continue;
        }

        long long n1 = pq.top(); pq.pop();
        long long n2 = pq.top(); pq.pop();
        long long n3 = pq.top(); pq.pop();

        long long result = n1 * n2 * n3;

        cout << -result << '\n';

        pq.push(n1);
        pq.push(n2);
        pq.push(n3);
    }
    return 0;
}