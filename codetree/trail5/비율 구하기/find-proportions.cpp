#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int N;

    cin >> N;

    map<string, int> M;

    for(int i = 0; i < N; i++) {
        cin >> str;

        if(M.find(str) != M.end()) {
            M[str] += 1;
        }else {
            M[str] = 1;
        }
    }
    
    cout << fixed << setprecision(4);

    map<string, int>::iterator it;
    for(it = M.begin(); it != M.end(); it++) {

        cout << it->first << " " << (it->second / (double)N) * 100<< '\n';

    }

    return 0;
}