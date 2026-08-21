#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    string a;

    cin >> a;



    int n = a.size();

    string command;
    
    cin >> command;

    for(int i = 0; i < (int)command.size(); i++) {
        if(command[i] == 'L') {
            a = a.substr(1, n-1) + a.substr(0, 1);
        }else {
            a = a.substr(n-1, 1) + a.substr(0, n-1);
        }
    }

    cout << a; 
    
    return 0;
}