#include <iostream>
using namespace std;

int main() {

    string str;
    char c;

    cin >> str >> c;

    if(str.find(c) != string::npos) {
        cout << str.find(c);
    }
    else {
        cout << "No";
    }
    
    return 0;
}