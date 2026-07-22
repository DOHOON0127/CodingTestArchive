#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Dot {
    public:
        int x;
        int y;
        int num;

        Dot(int x, int y, int num) {
            this->x = x;
            this->y = y;
            this->num = num;
        }

        Dot(){}
};

int N;
int h[1000];
int w[1000];
Dot dots[1000];

bool cmp(Dot a, Dot b) {
    if(abs(a.x) + abs(a.y) != abs(b.x) + abs(b.y)) {
        return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
    }
    else {
        return a.num < b.num;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> h[i] >> w[i];

        dots[i] = Dot(h[i], w[i], i+1);
    }

    sort(dots, dots+N, cmp);

    for(int i = 0; i < N; i++) {
        cout << dots[i].num << '\n';
    }

    return 0;
}