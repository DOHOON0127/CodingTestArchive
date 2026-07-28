#include <iostream>
#include <list>
using namespace std;

int n;
string str;

list<int> L;

int main() {

    cin >> n;


    for(int i = 0; i < n; i++) {
        cin >> str;
        
        int a;

        if(str == "push_back"){
            cin >> a;
            L.push_back(a);
        }
        else if(str == "push_front") {
            cin >> a;
            L.push_front(a); 
        }
        else if(str == "pop_front") {
            int front = L.front();
            L.pop_front();
            cout << front << '\n';
        }       
        else if(str == "pop_back") {
            int front = L.back();
            L.pop_back();
            cout << front << '\n';
        }
        else if(str == "size") {
            cout << L.size() << '\n';
        }
        else if(str == "empty") {
            if(L.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }      
        else if(str == "front") {
            cout << L.front() << '\n';
        }   
        else if(str == "back") {
            cout << L.back() << '\n';
        }               
    }


    return 0;
}