#include <iostream>
#include <climits>
using namespace std;

int arr[5];

int min_team_power = INT_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];

        sum += arr[i];
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {

                if(i == j || j == k || k == i) {
                    continue;
                }

                int x = arr[i];
                int y = arr[j] + arr[k];
                int z = sum - x - y;

                if(x == y || y == z || z == x) {
                    continue;
                }

                int min_sum = abs(x-y);
                min_sum = max(min_sum, abs(x-z));
                min_sum = max(min_sum, abs(y-z));

                min_team_power = min(min_team_power, min_sum);
            }
        }
    }

    if(min_team_power == INT_MAX) {
        cout << -1;
    }
    else {
        cout << min_team_power;
    }

    return 0;
}