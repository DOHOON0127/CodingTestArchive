#include <iostream>
#include <climits>
using namespace std;

// int a,b,c,d,e,f;
int arr[6];
int team_min = INT_MAX;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> a >> b >> c >> d >> e >> f;
    int sum = 0;

    for(int i = 0; i < 6; i++) {
        cin >> arr[i];

        sum += arr[i];
    }

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            for(int p = 0; p < 6; p++) {
                for(int q = 0; q < 6; q++) {

                    if(i == j || j == p || p == q || q == i || i == p || j == q) {
                        continue;
                    }

                    int x = arr[i] + arr[j];
                    int y = arr[p] + arr[q];
                    int z = sum - x - y;

                    int temp_max = 0;
                    int temp_min = 0;

                    if(x > y) {
                        temp_max = x;
                        temp_min = y;
                    }
                    else {
                        temp_max = y;
                        temp_min = x;
                    }

                    int max_num = max(temp_max,z);
                    int min_num = min(temp_min,z);

                    team_min = min(team_min, max_num - min_num);
                
                }
            }
        }
    }

    cout << team_min;

    return 0;
}