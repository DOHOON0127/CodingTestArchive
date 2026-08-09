#include <iostream>
#include <climits>
using namespace std;

int n;
int x[100];
int y[100];
int min_dis = INT_MAX;

int dis_two(int x, int y, int x1, int y1) {
    return (x1-x)*(x1-x) + (y1-y)*(y1-y);
}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for(int i =0; i < n; i++) {
        for(int j = i+1; j < n; j++) {

            int max = dis_two(x[i], y[i], x[j], y[j]);

            min_dis = min(min_dis, max);
        }
    }
    
    cout << min_dis;

    return 0;
}