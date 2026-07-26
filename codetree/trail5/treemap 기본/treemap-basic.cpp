#include <iostream>
#include <map>
using namespace std;

int n;

int main() {
    cin >> n;

    string str;
    int k, v;

    map<int, int> M;

    for(int i = 0; i < n; i++) {
        cin >> str;

        if(str == "add") {
            cin >> k >> v;
            M[k] = v;
        }
        else if(str == "remove") {
            cin >> k;
            M.erase(k);

        }
        else if(str == "find") {
            cin >> k;
            if(M.find(k) == M.end()) {
                cout << "None" << '\n';
            }
            else{
                cout << M.find(k)->second << '\n';
            }
        }
        else {
            if(M.empty()) {
                cout << "None" << '\n';
            }
            else {
                map<int, int>::iterator it;
                for(it = M.begin(); it != M.end(); it++) {
                    cout << it->second << " ";
                }
                cout << '\n';
            }
        }
    }
    return 0;
}