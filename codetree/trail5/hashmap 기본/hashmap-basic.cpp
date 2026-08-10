#include <iostream>
#include <unordered_map>
using namespace std;

int n;
unordered_map<int, int> m;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        string command;
        int a;
        int b;

        cin >> command;

        if (command == "add") {
            cin >> a >> b;
            m[a] = b;
        }
        else if (command == "remove") {
            cin >> a;
            m.erase(a);
        }
        else {
            cin >> a;
            if (m.find(a) == m.end()) {
                cout << "None" << '\n';
            }
            else {
                cout << m.find(a)->second << '\n';
            }

        }
    }


    return 0;
}