#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int n;
unordered_map<string, int> M;
string arr[100000];
int max_num = INT_MIN;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (M.find(arr[i]) == M.end()) {
            M[arr[i]] = 1;
        }
        else {
            M[arr[i]] += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int max_temp_num = M[arr[i]];
        max_num = max(max_num, max_temp_num);
    }

    cout << max_num;


    return 0;
}