#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

int N, M; // n개의 보석과, 가방의 크기m
int w[100000]; // 무게
int v[100000]; // 가치

int arr[100000];

vector<pair<double, int>> V;

int main() {
    cin >> N >> M; 

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
        V.push_back({(double)v[i] / w[i], i});
    }

    sort(V.begin(), V.end(), greater<>());   

    double maxVal;

    for(int i = 0; i < N ; i++) {

        if(M == 0) {
            break;
        }
        
        if(M - w[V[i].second] >= 0) {
            M = M - w[V[i].second];
            maxVal += v[V[i].second];
        }
        else {
            maxVal += (M / (double)w[V[i].second]) * v[V[i].second];
            M = 0;
        }

    }

    cout << fixed << setprecision(3);

    cout << maxVal;

    return 0;
}
