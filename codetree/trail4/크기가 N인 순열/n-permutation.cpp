#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> V;
bool visited[10];

void printVector() {
    for(int i = 0; i < V.size(); i++) {
        cout << V[i] << ' ';
    }
    cout << '\n';
}

void choose(int curr_num) {

    if(curr_num == n+1) {
        printVector();
        return;
    }


    for(int i = 1; i <= n; i++) {

        if(visited[i]) {
            continue;
        }

        V.push_back(i);

        visited[i] = true;

        choose(curr_num+1);

        V.pop_back();

        visited[i] = false;

    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    choose(1);

    return 0;
}
