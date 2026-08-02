#include <iostream>
// 각 방에 정해진 인원이 들어가는 데까지 거리의 합의 최솟값
#include <climits>

using namespace std;

int n;
int arr[1004];

int min_dist = INT_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    } 

    for(int i = 1; i <= n; i++) {
        
        int sum_dist = 0;

        for(int j = 1; j <= n; j++) {


            if(j < i) {
                sum_dist += (n - i + j) * arr[j];
            }
            else if(i == j) {
                continue;
            }
            else {
                sum_dist += (j - i) * arr[j];
            }

        }

        min_dist = min(min_dist, sum_dist);

    }

    cout << min_dist;

    return 0;
}