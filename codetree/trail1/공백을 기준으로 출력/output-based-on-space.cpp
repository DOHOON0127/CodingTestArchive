#include <iostream>
using namespace std;

int main() {

    string str1;
    string str2;

    getline(cin, str1);
    getline(cin, str2); 

    for(char c : str1) {
        if(c != ' ') {
            cout << c;
        }
    }

    for(char c : str2) {
        if(c != ' ') {
            cout << c;
        }
    }

    return 0;
}