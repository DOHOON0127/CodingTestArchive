#include <iostream>
using namespace std;

string str;

int main() {

    cin >> str;

    int len = (int)str.size();
    
    for(int i = len-1; i >= 0; i--) {
        if(i % 2 != 0) {
            cout << str[i];
        }
    }

    return 0;
}