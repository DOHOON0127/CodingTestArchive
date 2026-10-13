#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int n;
int arr[100000];

int main() {
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    // 가장 작은 수 2개를 구하기
    // 최소 비용을 구해야 하는데
    int minCost = 0;

    // 4
    // 1 2 2 3
    // 2 2 3
    // 3 4
    // 7
    
    for (int i = 0; i < n; i++) {
        if (pq.size() == 1) break;
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);
    
        minCost += (a + b);
    }
    
    cout << minCost;

    return 0;
}
