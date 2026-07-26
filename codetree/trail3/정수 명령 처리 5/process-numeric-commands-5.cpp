#include <iostream>
#include <vector> 
using namespace std;

int n;

int main() {

    cin >> n;
    string str;
    int num;

    vector<int> V;

    for(int i = 0; i < n; i++) {
        cin >> str;

        if(str == "push_back") {
            cin >> num;
            V.push_back(num);
        }
        else if(str == "pop_back") {
            V.pop_back();
        }
        else if(str == "size") {
            cout << V.size() << '\n';
        }
        else {
            cin >> num;
            cout << V[num-1] << '\n';
        }
    }

    return 0;
}