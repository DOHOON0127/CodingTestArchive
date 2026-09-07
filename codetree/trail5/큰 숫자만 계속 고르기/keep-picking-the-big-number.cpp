#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[100000];
priority_queue<int> pq;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    for(int i = 0; i < m; i++) {
        int temp = pq.top()-1;
        pq.pop();
        pq.push(temp);
    }

    cout << pq.top();



    return 0;
}
