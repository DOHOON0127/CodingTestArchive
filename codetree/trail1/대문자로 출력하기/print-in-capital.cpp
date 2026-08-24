#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string str;

    cin >> str;

    for(int i = 0; i < (int)str.size(); i++) {
        if(isalpha(str[i])) {
            cout << (char)toupper(str[i]);
        }
    }
    
    return 0;
}
