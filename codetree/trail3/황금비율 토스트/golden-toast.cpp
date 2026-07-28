#include <iostream>
#include <string>
#include <list>
using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m; // 식빵 개수, 암호문 개수
    cin >> s; // 문자열, 문자열 길이 == n

    list<char> L;
    list<char>::iterator it;

    for(int i = 0; i < (int)s.size(); i++) {
        L.push_back(s[i]);
    }

    it = L.end();

    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        if (command == 'P') {
            char c;
            cin >> c;

            L.insert(it, c);
        }
        else if(command == 'L') {
            if(it != L.begin())
                it--;
        }
        else if(command == 'R') {
            if(it != L.end())
                it++;
        }
        else if(command == 'D') {
            if(it != L.end())
                it = L.erase(it);
        }
    }

    for(it = L.begin(); it != L.end(); it++) {
        cout << *it;
    }


    return 0;
}
