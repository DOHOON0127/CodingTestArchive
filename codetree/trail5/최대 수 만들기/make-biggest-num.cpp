#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[50000];

bool cmp(const string& a, const string& b) {
    if((a+b) > (b+a)) {
        return true;
    }
    return false;
}


int main() {
    cin >> n;

    vector<string> V;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        V.push_back(to_string(arr[i]));
    }

    sort(V.begin(), V.end(), cmp);

    string ans = "";

    for(int i = 0; i < V.size(); i++) {
        ans += V[i];
    }

    cout << ans;
    

    return 0;
}
