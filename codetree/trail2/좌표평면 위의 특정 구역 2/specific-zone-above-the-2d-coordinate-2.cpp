#include <iostream>
#include <climits>
using namespace std;

int n;
int x[100];
int y[100];
int min_square = INT_MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i = 0; i < n; i++) {
        int max_x = INT_MIN;
        int max_y = INT_MIN;
        int min_x = INT_MAX;
        int min_y = INT_MAX;

        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            
            max_x = max(max_x, x[j]);
            max_y = max(max_y, y[j]);
            min_x = min(min_x, x[j]);
            min_y = min(min_y, y[j]);
        }

        int square = (max_x - min_x) * (max_y-min_y);

        min_square = min(min_square, square);
    }

    cout << min_square;

    return 0;
}