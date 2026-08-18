#include <iostream>
using namespace std;

string str1;    
string str2;

int main() {

    cin >> str1 >> str2;

    if(str1.size() == str2.size()) {
        cout << "same";
    }
    else if(str1.size() > str2.size()) {
        cout << str1 << " " << str1.size();
    }
    else {
        cout << str2 << " " << str2.size();
    }

    return 0;
}