#include <iostream>
#include <queue>
using namespace std;

int main() { 

    priority_queue<int> pq;

    int n;
    cin >> n;
    
    string str;
    int a;

    while(n--) {
        
        cin >> str;

        if(str == "push") {
            cin >> a;
            pq.push(a);
        }
        else if(str == "size") {
            cout << pq.size() << '\n';
        }
        else if(str == "empty") {
            if(pq.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if(str == "pop") {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else if(str == "top") {
            cout << pq.top() << '\n';
        }
    }


    return 0;
}